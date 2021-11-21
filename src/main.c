/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/21 11:19:12 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdlib.h>

/*
 * Main function
*/
int	main(int argc, char *argv[])
{
	t_game_data	game_data;

	if (argc == 2)
	{
		if (validate_map(argv[1], &game_data) > 0)
			exit_strategy("Error\n Map incorrectly formatted\n", EXIT_SUCCESS);
	}
	else
		exit_strategy("Error\n Too little or too many arguments\n", EXIT_SUCCESS);
	render(&game_data);
	return (0);
}
