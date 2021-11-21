/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 11:08:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/21 11:58:36 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <get_next_line.h>

/*
 * Checks if border of the map is all walls
*/
int	border_check(t_game_data *gd, int row, int column)
{
	if (row == 0 || row == gd->map_height - 1)
	{
		if (gd->map[row][column] != '1')
			return (1);
	}
	else if (column == 0 || column == gd->map_width - 1)
	{
		if (gd->map[row][column] != '1')
			return (1);
	}
	return (0);
}

/*
 * Goes through each character to see if it is part of the set
*/
int	value_check(t_game_data *gd, int row, int column)
{
	if (gd->map[row][column] == 'E')
		gd->minimum_exits--;
	if (gd->map[row][column] == 'C')
		gd->minimum_collectibles--;
	if (gd->map[row][column] == 'P')
		gd->minimum_players--;
	if (ft_strchr(gd->map_values, gd->map[row][column]) == 0)
		return (1);
	if (row == gd->map_height - 1 && column == gd->map_width - 1)
	{
		if (gd->minimum_exits > 0 || gd->minimum_players > 0
			|| gd->minimum_collectibles > 0)
		{
			return (1);
		}
	}
	return (0);
}

/*
 * Goes through each line to see if file is a rectanguler shape
*/
int	rect_check(t_game_data *gd, int row, int column)
{
	static int	prev_len;
	static int	row_len;

	if (column == 0)
	{
		if (row == 0)
			prev_len = ft_strlen(gd->map[row]);
		row_len = ft_strlen(gd->map[row]);
		if (prev_len != row_len)
			return (1);
		else
			prev_len = row_len;
	}
	return (0);
}

/*
 * Compares last three letters of path and valid file name
*/
int	file_name_check(t_game_data *gd)
{
	int	path_len;

	path_len = ft_strlen(gd->map_path);
	if (ft_strncmp(&gd->map_path[path_len - 3], "ber", 4) != 0)
		return (1);
	return (0);
}
