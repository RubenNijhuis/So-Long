/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/24 14:26:27 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <stdint.h>
#include <stdlib.h>

int32_t	main(int argc, char *argv[])
{
	t_game_data	game_data;

	ft_bzero(&game_data, sizeof(game_data));
	if (argc != 2)
		exit_strategy("Error\n Too little or too many arguments\n", EXIT_SUCCESS);
	if (validate_map(argv[1], &game_data) > 0)
		exit_strategy("Error\n Map incorrectly formatted\n", EXIT_SUCCESS);
	render(&game_data);
	return (0);
}
