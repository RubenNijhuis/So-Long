/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/19 12:45:38 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <libft.h>
#include <stdio.h>

int	main(void)
{
	struct s_game_data	game_data;

	if (validate_map("assets/map2.ber", &game_data) > 0)
		printf("ERROR: Map not found or incorrectly formatted\n");
	render(&game_data);
	return (0);
}
