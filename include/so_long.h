/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 14:16:01 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/24 14:22:09 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stdbool.h>

# define PLAYER_DIR_UP "assets/imgs/player_up.xpm"
# define PLAYER_DIR_RIGHT "assets/imgs/player_right.xpm"
# define PLAYER_DIR_DOWN "assets/imgs/player_down.xpm"
# define PLAYER_DIR_LEFT "assets/imgs/player_left.xpm"

# define SPACE_IMG_PATH "assets/imgs/ground.xpm"
# define WALL_IMG_PATH "assets/imgs/wall.xpm"
# define COLLECTIBLE_IMG_PATH "assets/imgs/collectible.xpm"
# define MAP_EXIT_IMG_PATH "assets/imgs/exit.xpm"

# define MIN_COLLECTIBLES 3
# define MIN_PLAYERS 1
# define MIN_EXITS 1

# define IMG_RES 32
# define PROGRAM_NAME "so_long"

# define MAP_VALUES "01CEP"

typedef enum e_keys
{
	key_up = 13,
	key_down = 1,
	key_right = 2,
	key_left = 0,
}	t_keys;

typedef enum e_player_directions
{
	up_dir,
	left_dir,
	right_dir,
	down_dir,
}	t_player_directions;

typedef struct s_player
{
	void		*player_img_up;
	void		*player_img_right;
	void		*player_img_down;
	void		*player_img_left;

	uint32_t	player_direction;
	uint32_t	player_total_moves;
	uint32_t	player_x;
	uint32_t	player_y;
}	t_player;

typedef struct s_mlx_inst
{
	void		*mlx;
	void		*win;
	uint32_t	total_frames;
}	t_mlx_inst;

typedef struct s_map
{
	char		**map;
	char		*map_path;
	uint32_t	map_height;
	uint32_t	map_width;
}	t_map;

typedef struct s_textures
{
	void	*empty_space_img;
	void	*wall_img;
	void	*collectible_img;
	void	*map_exit_img;
}	t_textures;

typedef struct s_goal
{
	uint32_t	amount_collectibles;
	bool		allowed_to_exit;
}	t_goal;

typedef struct s_game_data
{
	t_player	player;
	t_goal		goal;

	t_mlx_inst	mlx_inst;

	int			res;
	t_map		map;

	t_textures	textures;
}	t_game_data;

void	initialize_map(char *path, t_map *map);
void	initialize_game(t_game_data *gd);
void	initialize_all_images(t_game_data *gd);

void	exit_strategy(char *message, int status);

int		check_movement_valid(int keycode, t_game_data *gd);
void	update_player_position(int keycode, t_game_data *gd);
int		key_hook(int keycode, t_game_data *gd);

void	render(t_game_data *gd);
int		render_map(t_game_data *gd, uint32_t row, uint32_t column);
void	render_image(char type, uint32_t row, uint32_t column, t_game_data *gd);
void	render_player(t_player *player, t_mlx_inst *mlx_inst);

void	set_map_size(t_game_data *gd);
int		set_player_position(t_game_data *gd, uint32_t row, uint32_t column);
int		set_amount_collectibles(t_game_data *gd, uint32_t row, uint32_t column);

int		rect_check(t_game_data *gd, uint32_t row, uint32_t column);
int		border_check(t_game_data *gd, uint32_t row, uint32_t column);
int		value_check(t_game_data *gd, uint32_t row, uint32_t column);
int		file_name_check(t_game_data *gd);

int		validate_map(char *path, t_game_data *gd);
char	**parse_map(int fd);
int		go_through_map(t_game_data *gd,
			int (*f)(t_game_data *gd, uint32_t row, uint32_t column));

#endif