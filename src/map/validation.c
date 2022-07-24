/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 11:08:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/24 14:22:18 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

/*
 * Checks if border of the map is all walls
*/
int	border_check(t_game_data *gd, uint32_t row, uint32_t column)
{
	if (row == 0 || row == gd->map.map_height - 1)
	{
		if (gd->map.map[row][column] != '1')
			return (1);
	}
	else if (column == 0 || column == gd->map.map_width - 1)
	{
		if (gd->map.map[row][column] != '1')
			return (1);
	}
	return (0);
}

/*
 * Goes through each character to see if it is part of the set
*/
int	value_check(t_game_data *gd, uint32_t row, uint32_t column)
{
	if (ft_strchr(MAP_VALUES, gd->map.map[row][column]) == 0)
		return (1);
	return (0);
}

/*
 * Goes through each line to see if file is a rectanguler shape
*/
int	rect_check(t_game_data *gd, uint32_t row, uint32_t column)
{
	static int	prev_len;
	static int	row_len;

	if (column == 0)
	{
		if (row == 0)
			prev_len = ft_strlen(gd->map.map[row]);
		row_len = ft_strlen(gd->map.map[row]);
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
	size_t	path_len;

	path_len = ft_strlen(gd->map.map_path);
	if (ft_strncmp(&gd->map.map_path[path_len - 4], ".ber", 4) != 0)
		return (1);
	return (0);
}
