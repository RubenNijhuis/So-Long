/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 11:08:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/16 16:41:15 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "../include/so_long.h"
#include "../include/libft.h"
#include "../include/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	validate_map(s_game_data *game_data)
{
	int		fd;
	char	*tmp_string;
	char	**map;

	string = "\0";
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error! Could not open file\n");
		exit(-1);
	}
	map = parse_map(game_data->);
}

char	**parse_map(s_game_data* game_data)
{
	char	*string;
	char	*tmp_string;
	char	**map;

	string = "\0";
	while (tmp_string != NULL)
	{
		tmp_string = get_next_line(fd);
		if (tmp_string != NULL)
		{
			string = ft_strjoin(string, tmp_string);
			if (string == NULL)
				return (NULL);
		}
		free(tmp_string);
	}
	map = ft_split(string, '\n');
	return (map);
}
