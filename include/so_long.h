/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 14:16:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/21 14:22:44 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
typedef struct s_enemy
{
	int	direction;
	int	position_x;
	int	position_y;
} t_enemy;

typedef struct s_game_data
{
	void	*mlx;
	void	*win;
	int		total_frames;
	int		res;
	t_list	enemies;

	char	*name;
	char	**map;
	char	*map_path;
	char	*map_values;
	int		map_height;
	int		map_width;

	int		minimum_collectibles;
	int		minimum_players;
	int		minimum_exits;

	int		amount_collectibles;
	int		amount_enemies;
	int		player_direction;
	int		player_total_moves;
	int		player_x;
	int		player_y;
	int		allowed_to_exit;

	int		key_up;
	int		key_left;
	int		key_right;
	int		key_down;

	void	*empty_space_img;
	void	*wall_img;
	void	*collectible_img;
	void	*map_exit_img;

	void	*player_img_up;
	void	*player_img_right;
	void	*player_img_down;
	void	*player_img_left;

	char	*empty_space_img_path;
	char	*wall_img_path;
	char	*collectible_img_path;
	char	*map_exit_img_path;

	char	*player_img_up_path;
	char	*player_img_right_path;
	char	*player_img_down_path;
	char	*player_img_left_path;
}t_game_data;

void	initialize_map(char *path, t_game_data *gd);
void	initialize_enemy(t_game_data *gd);
void	initialize_player(t_game_data *gd);
void	initialize_game(t_game_data *gd);
void	initialize_all_images(t_game_data *gd);

void	exit_strategy(char *message, int status);

int		check_movement_valid(int keycode, t_game_data *gd);
void	update_player_position(int keycode, t_game_data *gd);
int		key_hook(int keycode, t_game_data *gd);

void	render(t_game_data *gd);
int		render_map(t_game_data *gd, int row, int column);
void	render_image(char type, int row, int column, t_game_data *gd);
void	render_player(t_game_data *gd);
void	*create_window(t_game_data *gd);

void	set_map_size(t_game_data *gd);
int		set_player_position(t_game_data *gd, int row, int column);
int		set_amount_collectibles(t_game_data *gd, int row, int column);

int		rect_check(t_game_data *gd, int row, int column);
int		border_check(t_game_data *gd, int row, int column);
int		value_check(t_game_data *gd, int row, int column);
int		file_name_check(t_game_data *gd);

int		validate_map(char *path, t_game_data *gd);
char	**parse_map(int fd);
int		go_through_map(t_game_data *gd,
			int (*f)(t_game_data *gd, int row, int column));

#endif