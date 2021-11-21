/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 10:53:02 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/21 11:11:31 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Checks if desired position is a valid one
*/
int	check_movement_valid(int keycode, t_game_data *gd)
{
	if (keycode == gd->key_left)
	{
		if (gd->map[gd->player_y][gd->player_x - 1] == '1')
			return (0);
	}
	else if (keycode == gd->key_right)
	{
		if (gd->map[gd->player_y][gd->player_x + 1] == '1')
			return (0);
	}
	else if (keycode == gd->key_up)
	{
		if (gd->map[gd->player_y - 1][gd->player_x] == '1')
			return (0);
	}
	else if (keycode == gd->key_down)
	{
		if (gd->map[gd->player_y + 1][gd->player_x] == '1')
			return (0);
	}
	return (1);
}

/*
 * Changes player position and direction
*/
void	update_player_position(int keycode, t_game_data *gd)
{
	if (keycode == gd->key_left)
	{
		gd->player_direction = 4;
		gd->player_x--;
	}
	else if (keycode == gd->key_right)
	{
		gd->player_direction = 2;
		gd->player_x++;
	}
	else if (keycode == gd->key_up)
	{
		gd->player_direction = 1;
		gd->player_y--;
	}
	else if (keycode == gd->key_down)
	{
		gd->player_direction = 3;
		gd->player_y++;
	}
	if (gd->map[gd->player_y][gd->player_x] == 'C')
	{
		gd->amount_collectibles--;
		gd->map[gd->player_y][gd->player_x] = '0';
	}
	if (gd->map[gd->player_y][gd->player_x] == 'E' &&
		gd->amount_collectibles == 0)
		exit_strategy("Game finished!\n", EXIT_SUCCESS);
}

/*
 * Runs on each button press
*/
int	key_hook(int keycode, t_game_data *gd)
{
	if (keycode == 53)
		exit_strategy("Game closed\n", EXIT_SUCCESS);
	if (keycode == gd->key_up || keycode == gd->key_down
		|| keycode == gd->key_left || keycode == gd->key_right)
	{
		if (check_movement_valid(keycode, gd))
		{
			gd->player_total_moves++;
			update_player_position(keycode, gd);
			printf("Total player moves: %i\n", gd->player_total_moves);
		}
	}
	return (0);
}
