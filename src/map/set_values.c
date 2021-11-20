/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_values.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 01:02:07 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/20 11:10:21 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <stdio.h>

void	set_map_size(struct s_game_data *gd)
{
	gd->map_height = 0;
	while (gd->map[gd->map_height] != NULL)
		gd->map_height += 1;
	gd->map_width = ft_strlen(gd->map[0]);
}

void	set_player_position(struct s_game_data *gd)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < gd->map_height)
	{
		while (column < gd->map_width)
		{
			if (gd->map[row][column] == 'P')
			{
				gd->player_x = column;
				gd->player_y = row;
			}
			column++;
		}
		column = 0;
		row++;
	}
}

void	set_amount_collectibles(struct s_game_data *gd)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	gd->amount_collectibles = 0;
	while (row < gd->map_height)
	{
		while (column < gd->map_width)
		{
			if (gd->map[row][column] == 'C')
			{
				gd->amount_collectibles++;
			}
			column++;
		}
		column = 0;
		row++;
	}
}
