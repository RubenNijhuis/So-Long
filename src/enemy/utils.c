/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 11:44:35 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/12/13 16:39:25 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

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

/*
 * Create an enemy
*/
t_enemy	*create_enemy(int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	new_enemy->position_x = x;
	new_enemy->position_y = y;
	new_enemy->direction = 1;
	if (new_enemy == NULL)
		return (NULL);
	return (new_enemy);
}

/*
 * Check for a valid enemy position
*/
int	valid_enemy_pos(t_game_data *gd, int row, int column)
{
	static int	enemies_placed;

	if (enemies_placed == 0)
		enemies_placed = 0;
	if (gd->map[row][column] == '0' && enemies_placed < gd->amount_enemies)
	{
		gd->enemies[enemies_placed]->position_x = column;
		gd->enemies[enemies_placed]->position_y = row;
		enemies_placed++;
	}
	return (0);
}

/*
 * Place all enemies
*/
int	place_enemies(t_game_data *gd, int row, int column)
{
	static int	amount_placed;

	if (gd->map[row][column] == 'B')
	{
		gd->enemies[amount_placed] = create_enemy(row, column);
		if (gd->enemies[amount_placed] == NULL)
		{
			exit_strategy("Error\nMallocing of enemies array failed",
				EXIT_FAILURE);
			return (1);
		}
		amount_placed++;
	}
	return (0);
}

/*
 * Create 2d enemies array
*/
void	create_enemies(t_game_data *gd)
{
	int		i;

	i = 0;
	gd->enemies = malloc(gd->amount_enemies * sizeof(t_enemy *));
	if (gd->enemies == NULL)
		exit_strategy("Error\nMallocing of enemies array failed", EXIT_FAILURE);
	go_through_map(gd, place_enemies);
}
