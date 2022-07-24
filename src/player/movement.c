/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 10:53:02 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/24 14:30:34 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Checks if desired position is a valid one
*/
int	check_movement_valid(int keycode, t_game_data *gd)
{
	if (keycode == key_left)
	{
		if (gd->map.map[gd->player.player_y][gd->player.player_x - 1] == '1')
			return (0);
	}
	else if (keycode == key_right)
	{
		if (gd->map.map[gd->player.player_y][gd->player.player_x + 1] == '1')
			return (0);
	}
	else if (keycode == key_up)
	{
		if (gd->map.map[gd->player.player_y - 1][gd->player.player_x] == '1')
			return (0);
	}
	else if (keycode == key_down)
	{
		if (gd->map.map[gd->player.player_y + 1][gd->player.player_x] == '1')
			return (0);
	}
	return (1);
}

void	update_player_direction(int keycode, t_game_data *gd)
{
	if (keycode == key_left)
		gd->player.player_direction = left_dir;
	else if (keycode == key_right)
		gd->player.player_direction = right_dir;
	else if (keycode == key_up)
		gd->player.player_direction = up_dir;
	else if (keycode == key_down)
		gd->player.player_direction = down_dir;
}

/*
 * Changes player position and direction
*/
void	update_player_position(int keycode, t_game_data *gd)
{
	if (keycode == key_left)
		gd->player.player_x--;
	else if (keycode == key_right)
		gd->player.player_x++;
	else if (keycode == key_up)
		gd->player.player_y--;
	else if (keycode == key_down)
		gd->player.player_y++;
	if (gd->map.map[gd->player.player_y][gd->player.player_x] == 'C')
	{
		gd->goal.amount_collectibles--;
		gd->map.map[gd->player.player_y][gd->player.player_x] = '0';
	}
	update_player_direction(keycode, gd);
	if (gd->map.map[gd->player.player_y][gd->player.player_x] == 'E' &&
		gd->goal.amount_collectibles == 0)
		exit_strategy("Game finished!\n", EXIT_SUCCESS);
}

/*
 * Runs on each button press
*/
int	key_hook(int keycode, t_game_data *gd)
{
	if (keycode == 53)
		exit_strategy("Game closed\n", EXIT_SUCCESS);
	if (keycode == key_up || keycode == key_down
		|| keycode == key_left || keycode == key_right)
	{
		if (check_movement_valid(keycode, gd))
		{
			gd->player.player_total_moves++;
			update_player_position(keycode, gd);
		}
	}
	return (0);
}
