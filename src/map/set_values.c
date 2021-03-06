/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_values.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 01:02:07 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/12/13 16:35:51 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*
 * Sets map size
*/
void	set_map_size(t_game_data *gd)
{
	while (gd->map[gd->map_height] != NULL)
		gd->map_height += 1;
	gd->map_width = ft_strlen(gd->map[0]);
}

/*
 * Sets player position
*/
int	set_player_position(t_game_data *gd, int row, int column)
{
	if (gd->map[row][column] == 'P')
	{
		gd->player_x = column;
		gd->player_y = row;
	}
	return (0);
}

/*
 * Sets the amount of collectibles on the map
*/
int	set_amount_collectibles(t_game_data *gd, int row, int column)
{
	if (gd->map[row][column] == 'C')
		gd->amount_collectibles++;
	return (0);
}

/*
 * Sets the amount of bad guys on the map
*/
int	set_amount_enemies(t_game_data *gd, int row, int column)
{
	if (gd->map[row][column] == 'B')
		gd->amount_enemies++;
	return (0);
}
