/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 16:13:41 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/20 09:19:55 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

void	initialize_images_data(struct s_game_data *gd)
{
	gd->empty_space_img_path = "assets/imgs/ground.xpm";
	gd->wall_img_path = "assets/imgs/wall.xpm";
	gd->collectible_img_path = "assets/imgs/collectible.xpm";
	gd->map_exit_img_path = "assets/imgs/exit.xpm";
	gd->player_img_path = "assets/imgs/small5.xpm";
	gd->empty_space_img = mlx_xpm_file_to_image(gd->mlx,
			gd->empty_space_img_path, &gd->res, &gd->res);
	gd->wall_img = mlx_xpm_file_to_image(gd->mlx,
			gd->wall_img_path, &gd->res, &gd->res);
	gd->collectible_img = mlx_xpm_file_to_image(gd->mlx,
			gd->collectible_img_path, &gd->res, &gd->res);
	gd->map_exit_img = mlx_xpm_file_to_image(gd->mlx,
			gd->map_exit_img_path, &gd->res, &gd->res);
	gd->player_img = mlx_xpm_file_to_image(gd->mlx,
			gd->player_img_path, &gd->res, &gd->res);
}

void	initialize_player_data(struct s_game_data *gd)
{
	gd->player_total_moves = 0;
	gd->key_up = 13;
	gd->key_down = 1;
	gd->key_right = 2;
	gd->key_left = 0;
	gd->total_frames = 0;
}

void	initialize_game(struct s_game_data *gd)
{
	gd->res = 32;
	gd->name = "So Long";
	gd->mlx = mlx_init();
	gd->win = create_window(gd);
}
