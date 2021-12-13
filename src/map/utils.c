/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:47:52 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/12/13 16:34:44 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <get_next_line.h>
#include <stdio.h>
#include <fcntl.h>

/*
 * Parses the map and puts it into a 2d array
*/
char	**parse_map(int fd)
{
	char	*string;
	char	*tmp_string;
	char	**map;
	int		first_time;

	first_time = 0;
	tmp_string = NULL;
	string = ft_calloc(1, sizeof(char));
	while (first_time == 0)
	{
		tmp_string = get_next_line(fd);
		if (tmp_string != NULL)
		{
			string = ft_strjoin(string, tmp_string);
			if (string == NULL)
				return (NULL);
			free(tmp_string);
		}
		else
			break ;
	}
	map = ft_split(string, '\n');
	free(string);
	return (map);
}

/*
 * High order function that runs a function based on each character in the map
*/
int	go_through_map(t_game_data *gd, int (*f)(t_game_data *gd,
		int row, int column))
{
	int	row;
	int	column;

	row = 0;
	while (row < gd->map_height)
	{
		column = 0;
		while (column < gd->map_width)
		{
			if (f(gd, row, column) == 1)
				return (1);
			column++;
		}
		row++;
	}
	return (0);
}

/*
 * General map validation
*/
int	validate_map(char *path, t_game_data *gd)
{
	int	fd;
	int	return_value;

	return_value = 0;
	initialize_map(path, gd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_strategy("Error\nCould not open file\n", EXIT_SUCCESS);
	gd->map = parse_map(fd);
	close(fd);
	set_map_size(gd);
	go_through_map(gd, set_player_position);
	go_through_map(gd, set_amount_collectibles);
	go_through_map(gd, set_amount_enemies);
	return_value += file_name_check(gd);
	return_value += go_through_map(gd, rect_check);
	return_value += go_through_map(gd, border_check);
	return_value += go_through_map(gd, value_check);
	return (return_value);
}
