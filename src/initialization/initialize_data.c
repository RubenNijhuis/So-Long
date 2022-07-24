/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 14:04:54 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/07/24 14:28:05 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/*
 * Initializes general game data
*/
void	initialize_game(t_game_data *gd)
{
	gd->mlx_inst.mlx = mlx_init();
	gd->mlx_inst.win = mlx_new_window(gd->mlx_inst.mlx, gd->map.map_width * IMG_RES,
			gd->map.map_height * IMG_RES, PROGRAM_NAME);
	gd->res = IMG_RES;
	gd->player.player_direction = down_dir;
}

/*
 * Initializes general map data
*/
void	initialize_map(char *path, t_map *map)
{
	map->map_path = path;
}