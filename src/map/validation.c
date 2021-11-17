/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 11:08:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/17 16:19:45 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx.h"
#include "../../include/so_long.h"
#include "../../include/libft.h"
#include "../../include/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	validate_map(char *path, struct s_game_data *gd)
{
	int	fd;
	int	return_value;

	return_value = 0;
	gd->map_values = "01CEP";
	gd->map_path = path;
	fd = open(gd->map_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error! Could not open file\n");
		exit(-1);
	}
	gd->map = parse_map(fd, gd);
	// set_map_size(gd);
	// return_value += rect_check(gd);
	// return_value += border_check(gd);
	// return_value += value_check(gd);
	return (return_value);
}

int	border_check(struct s_game_data *gd)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < gd->map_height)
	{
		while (column < gd->map_width)
		{
			column++;
		}
	}
	return (0);
}

int	value_check(struct s_game_data *gd)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < gd->map_height)
	{
		while (column < gd->map_width)
		{
			if (ft_strchr(gd->map_values, gd->map[row][column]) == 0)
				return (1);
			column++;
		}
		row++;
		column = 0;
	}
	return (0);
}

int	rect_check(struct s_game_data *gd)
{
	int	prev_len;
	int	row_len;
	int	row;

	prev_len = 0;
	row_len = 0;
	row = 0;
	while (gd->map[row][0] != '\0')
	{
		if (row == 0)
			prev_len = ft_strlen(gd->map[row]);
		row_len = ft_strlen(gd->map[row]);
		if (prev_len != row_len)
			return (1);
		else
			prev_len = row_len;
		row++;
	}
	return (0);
}
