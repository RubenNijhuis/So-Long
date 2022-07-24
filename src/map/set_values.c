/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_values.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 01:02:07 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/07/24 14:28:40 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

/*
 * Sets map size
*/
void	set_map_size(t_game_data *gd)
{
	while (gd->map.map[gd->map.map_height] != NULL)
		gd->map.map_height += 1;
	gd->map.map_width = ft_strlen(gd->map.map[0]);
}

/*
 * Sets player position
*/
int	set_player_position(t_game_data *gd, uint32_t row, uint32_t column)
{
	if (gd->map.map[row][column] == 'P')
	{
		gd->player.player_x = column;
		gd->player.player_y = row;
		gd->map.map[row][column] = '0';
	}
	return (0);
}

/*
 * Sets the amount of collectibles on the map
*/
int	set_amount_collectibles(t_game_data *gd, uint32_t row, uint32_t column)
{
	if (gd->map.map[row][column] == 'C')
		gd->goal.amount_collectibles++;
	return (0);
}
