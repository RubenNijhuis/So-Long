/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/18 16:13:28 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "../include/so_long.h"
#include "../include/libft.h"
#include <stdio.h>

int	main(void)
{
	struct s_game_data	game_data;

	game_data.name = "Ruben Nijhuis";
	if (validate_map("assets/map1.ber", &game_data) > 0)
		printf("Map not found or correctly formatted");
	initialize_game_data(&game_data);
	render(&game_data);
	return (0);
}
