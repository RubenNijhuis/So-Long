/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:47:52 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/21 10:38:39 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <get_next_line.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**parse_map(int fd, t_game_data *gd)
{
	char	*string;
	char	*tmp_string;
	char	**map;

	tmp_string = ft_calloc(1, sizeof(char));
	string = ft_calloc(1, sizeof(char));
	while (tmp_string != NULL)
	{
		tmp_string = get_next_line(fd);
		if (tmp_string != NULL)
		{
			string = ft_strjoin(string, tmp_string);
			if (string == NULL)
				return (NULL);
			free(tmp_string);
		}
	}
	map = ft_split(string, '\n');
	return (map);
}

int	validate_map(char *path, t_game_data *gd)
{
	int	fd;
	int	return_value;

	return_value = 0;
	initialize_map_data(path, gd);
	fd = open(gd->map_path, O_RDONLY);
	if (fd == -1)
		exit_strategy("Error\n Could not open file\n", EXIT_SUCCESS);
	gd->map = parse_map(fd, gd);
	set_map_size(gd);
	go_through_map(gd, set_player_position);
	go_through_map(gd, set_amount_collectibles);
	return_value += file_name_check(gd);
	return_value += go_through_map(gd, rect_check);
	return_value += go_through_map(gd, border_check);
	return_value += go_through_map(gd, value_check);
	return (return_value);
}
