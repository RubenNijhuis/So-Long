/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 14:16:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/20 01:11:14 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

struct s_game_data
{
	void	*mlx;
	void	*win;
	unsigned long int		total_frames;

	char	*name;
	char	**map;
	char	*map_path;
	char	*map_values;
	int		map_height;
	int		map_width;

	int		amount_collectibles;
	int		player_direction;
	int		player_total_moves;
	int		player_x;
	int		player_y;
	int		key_up;
	int		key_left;
	int		key_right;
	int		key_down;

	void	*empty_space_img;
	void	*wall_img;
	void	*collectible_img;
	void	*map_exit_img;
	void	*player_img;

	char	*empty_space_img_path;
	char	*wall_img_path;
	char	*collectible_img_path;
	char	*map_exit_img_path;
	char	*player_img_path;
};

void	initialize_game_data(struct s_game_data *gd);

void	exit_strategy(char *error, int err);

int		key_hook(int keycode, struct s_game_data *gd);

void	render(struct s_game_data *gd);
int		render_map(struct s_game_data *gd);
void	render_image(char type, int row, int column, struct s_game_data *gd);
void	render_player(struct s_game_data *gd);

void	set_player_position(struct s_game_data *gd);
void	set_map_size(struct s_game_data *gd);
int		rect_check(struct s_game_data *gd);
int		value_check(struct s_game_data *gd);
int		border_check(struct s_game_data *gd);
int		validate_map(char *path, struct s_game_data *gd);
char	**parse_map(int fd, struct s_game_data *gd);

#endif