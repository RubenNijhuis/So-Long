/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/20 11:16:26 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	struct s_game_data	game_data;

	if (argc == 2)
	{
		if (validate_map(argv[1], &game_data) > 0)
			exit_strategy("ERROR: Map not found or incorrectly formatted\n", EXIT_SUCCESS);
	}
	else
	{
		exit_strategy("Too many or too little arguments\n", EXIT_SUCCESS);
	}
	render(&game_data);
	return (0);
}
