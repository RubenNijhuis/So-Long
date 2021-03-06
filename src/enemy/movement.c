/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 22:43:50 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/12/13 15:45:10 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

int	check_player_position(t_game_data *gd, t_enemy *enemy, int keycode)
{
	if (keycode == gd->key_left)
	{
		if (enemy->position_y == gd->player_y
			&& enemy->position_x - 1 == gd->player_x)
			return (0);
	}
	else if (keycode == gd->key_right)
	{
		if (enemy->position_y == gd->player_y
			&& enemy->position_x + 1 == gd->player_x)
			return (0);
	}
	else if (keycode == gd->key_up)
	{
		if (enemy->position_y + 1 == gd->player_y
			&& enemy->position_x == gd->player_x)
			return (0);
	}
	else if (keycode == gd->key_down)
	{
		if (enemy->position_y - 1 == gd->player_y
			&& enemy->position_x == gd->player_x)
			return (0);
	}
	return (1);
}

int	check_all_enemy_positions(t_game_data *gd, t_enemy *enemy, int keycode)
{
	int	i;

	i = 0;
	if (check_player_position(gd, enemy, keycode) == 0)
		return (0);
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
				return (0);
		}
		i++;
	}
	return (1);
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
