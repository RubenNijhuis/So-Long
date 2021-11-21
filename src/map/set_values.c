/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_values.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 01:02:07 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/21 10:41:10 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>

void	set_map_size(t_game_data *gd)
{
	while (gd->map[gd->map_height] != NULL)
		gd->map_height += 1;
	gd->map_width = ft_strlen(gd->map[0]);
}

void	set_player_position(t_game_data *gd, int row, int column)
{
	if (gd->map[row][column] == 'P')
	{
		gd->player_x = column;
		gd->player_y = row;
	}
}

void	set_amount_collectibles(t_game_data *gd, int row, int column)
{
	if (gd->map[row][column] == 'C')
		gd->amount_collectibles++;
}
