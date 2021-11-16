/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 14:16:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/16 14:29:37 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

struct s_game_data
{
	char	**map;
	char	*map_path;
};

struct s_game_state
{
};

int		validate_map(char *path, s_game_data game_data);
char	**parse_map(char *path, s_game_data game_data);

#endif