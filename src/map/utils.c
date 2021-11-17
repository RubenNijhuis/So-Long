/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:47:52 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/17 16:22:06 by rnijhuis      ########   odam.nl         */
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
	printf("%s", gd->map[1]);
	// gd->map_height = 0;
	// while (gd->map[gd->map_height][0] != '\0')
	// 	gd->map_height += 1;
	// gd->map_width = ft_strlen(gd->map[0]);
}

char	**parse_map(int fd, struct s_game_data *gd)
{
	char	*string;
	char	*tmp_string;
	char	**map;

	gd->map_height = 0;
	string = malloc(sizeof(char));
	while (tmp_string != NULL)
	{
		tmp_string = get_next_line(fd);
		// printf("%s", /*ft_strlen(*/tmp_string);
		if (tmp_string != NULL)
		{
			string = ft_strjoin(string, tmp_string);
			if (string == NULL)
				return (NULL);
		}
		free(tmp_string);
	}
	printf("%c", string[5]);
	map = ft_split(string, '\n');
	return (map);
}
