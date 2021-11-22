/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 22:43:50 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/22 01:18:11 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

int	check_all_enemy_positions(t_game_data *gd, t_enemy *enemy, int keycode)
{
	int	i;

	i = 0;
	while (i < gd->amount_enemies)
	{
		if (keycode == gd->key_left)
		{
			if (enemy->position_y == gd->enemies[i]->position_y
				&& enemy->position_x - 1 == gd->enemies[i]->position_x)
				return (0);
		}
		else if (keycode == gd->key_right)
		{
			if (enemy->position_y == gd->enemies[i]->position_y
				&& enemy->position_x + 1 == gd->enemies[i]->position_x)
				return (0);
		}
		else if (keycode == gd->key_up)
		{
			if (enemy->position_y == gd->enemies[i]->position_y + 1
				&& enemy->position_x == gd->enemies[i]->position_x)
				return (0);
		}
		else if (keycode == gd->key_down)
		{
			if (enemy->position_y == gd->enemies[i]->position_y - 1
				&& enemy->position_x == gd->enemies[i]->position_x)
			{
				printf(": %i %i, 2: %i %i \n", enemy->position_x, enemy->position_y, gd->enemies[i]->position_x, gd->enemies[i]->position_y);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

/*
 * Checks if desired position is a valid one
*/
int	check_enemy_movement_valid(int keycode, t_game_data *gd, t_enemy *enemy)
{
	if (keycode == gd->key_left)
	{
		if (gd->map[enemy->position_y][enemy->position_x - 1] != '1' &&
			check_all_enemy_positions(gd, enemy, keycode))
			return (1);
	}
	else if (keycode == gd->key_right)
	{
		if (gd->map[enemy->position_y][enemy->position_x + 1] != '1' &&
			check_all_enemy_positions(gd, enemy, keycode))
			return (1);
	}
	else if (keycode == gd->key_up)
	{
		if (gd->map[enemy->position_y - 1][enemy->position_x] != '1' &&
			check_all_enemy_positions(gd, enemy, keycode))
			return (1);
	}
	else if (keycode == gd->key_down)
	{
		if (gd->map[enemy->position_y + 1][enemy->position_x] != '1' &&
			check_all_enemy_positions(gd, enemy, keycode))
			return (1);
	}
	return (0);
}

void	update_enemy_direction(int keycode, t_enemy *enemy, t_game_data *gd)
{
	if (keycode == gd->key_left)
		enemy->direction = 4;
	else if (keycode == gd->key_right)
		enemy->direction = 2;
	else if (keycode == gd->key_up)
		enemy->direction = 1;
	else if (keycode == gd->key_down)
		enemy->direction = 3;
}

/*
 * Changes player position and direction
*/
void	set_enemy_position(int keycode, t_enemy *enemy, t_game_data *gd)
{
	if (keycode == gd->key_left)
	{
		if (check_enemy_movement_valid(keycode, gd, enemy))
			enemy->position_x--;
	}
	else if (keycode == gd->key_right)
	{
		if (check_enemy_movement_valid(keycode, gd, enemy))
			enemy->position_x++;
	}
	else if (keycode == gd->key_up)
	{
		if (check_enemy_movement_valid(keycode, gd, enemy))
			enemy->position_y--;
	}
	else if (keycode == gd->key_down)
	{
		if (check_enemy_movement_valid(keycode, gd, enemy))
			enemy->position_y++;
	}
	update_enemy_direction(keycode, enemy, gd);
}

void	update_enemy_positions(t_game_data *gd)
{
	int	i;

	i = 0;
	while (i < gd->amount_enemies)
	{
		if ((gd->total_frames + i) % 10 == 1)
			set_enemy_position(gd->key_up, gd->enemies[i], gd);
		else if ((gd->total_frames + i) % 10 == 3)
			set_enemy_position(gd->key_down, gd->enemies[i], gd);
		else if ((gd->total_frames + i) % 10 == 5)
			set_enemy_position(gd->key_left, gd->enemies[i], gd);
		else if ((gd->total_frames + i) % 10 == 7)
			set_enemy_position(gd->key_right, gd->enemies[i], gd);
		i++;
	}
}
