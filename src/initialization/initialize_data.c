/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 14:04:54 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/21 22:02:24 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

/*
 * Initializes player data
*/
void	initialize_player(t_game_data *gd)
{
	gd->player_direction = 1;
	gd->player_total_moves = 0;
	gd->key_up = 13;
	gd->key_down = 1;
	gd->key_right = 2;
	gd->key_left = 0;
	gd->total_frames = 0;
}

/*
 * Initializes player data
*/
void	initialize_enemies(t_game_data *gd)
{
	create_enemies(gd);
}

/*
 * Initializes general game data
*/
void	initialize_game(t_game_data *gd)
{
	gd->res = 32;
	gd->name = "So Long";
	gd->mlx = mlx_init();
	gd->win = create_window(gd);
}

/*
 * Initializes general map data
*/
void	initialize_map(char *path, t_game_data *gd)
{
	gd->map_height = 0;
	gd->map_width = 0;
	gd->amount_collectibles = 0;
	gd->map_values = "01CEP";
	gd->map_path = path;
	gd->minimum_collectibles = 1;
	gd->minimum_exits = 1;
	gd->minimum_players = 1;
}
