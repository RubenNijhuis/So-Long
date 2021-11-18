/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:47:52 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/18 13:41:29 by rnijhuis      ########   odam.nl         */
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

void	set_map_size(struct s_game_data *gd)
{
	gd->map_height = 0;
	while (gd->map[gd->map_height] != NULL)
		gd->map_height += 1;
	gd->map_width = ft_strlen(gd->map[0]);
}

char	**parse_map(int fd, struct s_game_data *gd)
{
	char	*string;
	char	*tmp_string;
	char	**map;

	gd->map_height = 0;
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
