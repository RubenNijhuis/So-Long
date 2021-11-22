/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 11:44:35 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/22 02:00:39 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

/*
 * Create an enemy
*/
t_enemy	*create_enemy(void)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	new_enemy->position_x = 0;
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
	static int	offset;
	static int	enemies_placed;

	if (enemies_placed == 0)
		enemies_placed = 0;
	if (offset == 0)
		offset = 4;
	if (gd->map[row][column] == '0' && offset != 0
		&& enemies_placed < gd->amount_enemies)
	{
		gd->enemies[enemies_placed]->position_x = column;
		gd->enemies[enemies_placed]->position_y = row;
		enemies_placed++;
		offset--;
	}
	return (0);
}

/*
 * Place all enemies
*/
void	place_enemies(t_game_data *gd)
{
	int	i;

	i = 0;
	while (i < gd->amount_enemies)
	{
		gd->enemies[i]->position_x = 20;
		gd->enemies[i]->position_y = i + 1;
		i++;
	}
}

/*
 * Create 2d enemies array
 *
 * if (enemies[i] == NULL)
 * {
 *    free_enemies(enemies, i);
 *    exit_strategy("Error\nMallocing of enemies failed", EXIT_FAILURE);
 * }
*/
void	create_enemies(t_game_data *gd)
{
	int		total_chars;
	int		i;
	t_enemy	**enemies;

	i = 0;
	total_chars = gd->map_height * gd->map_width;
	gd->amount_enemies = total_chars / 100;
	enemies = malloc(gd->amount_enemies * sizeof(t_enemy *));
	if (enemies == NULL)
		exit_strategy("Error\nMallocing of enemies array failed", EXIT_FAILURE);
	while (i < gd->amount_enemies)
	{
		enemies[i] = create_enemy();
		i++;
	}
	gd->enemies = enemies;
	place_enemies(gd);
}
