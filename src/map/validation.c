/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 11:08:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/20 00:56:49 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <libft.h>
#include <get_next_line.h>

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
	set_map_size(gd);
	set_player_position(gd);
	return_value += rect_check(gd);
	return_value += border_check(gd);
	return_value += value_check(gd);
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
			if (row == 0 || row == gd->map_height - 1)
			{
				if (gd->map[row][column] != '1')
					return (1);
			}
			else
				if (column == 0 || column == gd->map_width - 1)
					if (gd->map[row][column] != '1')
						return (1);
			column++;
		}
		column = 0;
		row++;
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
		column = 0;
		row++;
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
	while (gd->map[row] != NULL)
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
