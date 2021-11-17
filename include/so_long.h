/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 14:16:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/17 15:55:33 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

struct s_game_data
{
	char	**map;
	char	*map_path;
	char	*map_values;
	int		map_height;
	int		map_width;
};

struct s_game_state
{
};

void	set_map_size(struct s_game_data *gd);
int		rect_check(struct s_game_data *gd);
int		value_check(struct s_game_data *gd);
int		border_check(struct s_game_data *gd);
int		validate_map(char *path, struct s_game_data *gd);
char	**parse_map(int fd, struct s_game_data *gd);

#endif