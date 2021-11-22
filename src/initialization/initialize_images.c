/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_images.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 16:13:41 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/22 11:34:02 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

/*
 * Initializes all images
*/
void	initialize_map_images(t_game_data *gd)
{
	gd->empty_space_img_path = "assets/imgs/ground.xpm";
	gd->wall_img_path = "assets/imgs/wall.xpm";
	gd->collectible_img_path = "assets/imgs/collectible.xpm";
	gd->map_exit_img_path = "assets/imgs/exit.xpm";
	gd->empty_space_img = mlx_xpm_file_to_image(gd->mlx,
			gd->empty_space_img_path, &gd->res, &gd->res);
	gd->wall_img = mlx_xpm_file_to_image(gd->mlx,
			gd->wall_img_path, &gd->res, &gd->res);
	gd->collectible_img = mlx_xpm_file_to_image(gd->mlx,
			gd->collectible_img_path, &gd->res, &gd->res);
	gd->map_exit_img = mlx_xpm_file_to_image(gd->mlx,
			gd->map_exit_img_path, &gd->res, &gd->res);
}

void	initialize_enemy_images(t_game_data *gd)
{
	gd->enemy_img_up_path = "assets/imgs/enemy_up.xpm";
	gd->enemy_img_right_path = "assets/imgs/enemy_right.xpm";
	gd->enemy_img_down_path = "assets/imgs/enemy_down.xpm";
	gd->enemy_img_left_path = "assets/imgs/enemy_left.xpm";
	gd->enemy_img_up = mlx_xpm_file_to_image(gd->mlx,
			gd->enemy_img_up_path, &gd->res, &gd->res);
	gd->enemy_img_right = mlx_xpm_file_to_image(gd->mlx,
			gd->enemy_img_right_path, &gd->res, &gd->res);
	gd->enemy_img_down = mlx_xpm_file_to_image(gd->mlx,
			gd->enemy_img_down_path, &gd->res, &gd->res);
	gd->enemy_img_left = mlx_xpm_file_to_image(gd->mlx,
			gd->enemy_img_left_path, &gd->res, &gd->res);
}

void	initialize_player_images(t_game_data *gd)
{
	gd->player_img_up_path = "assets/imgs/enemy_up.xpm";
	gd->player_img_right_path = "assets/imgs/enemy_right.xpm";
	gd->player_img_down_path = "assets/imgs/enemy_down.xpm";
	gd->player_img_left_path = "assets/imgs/enemy_left.xpm";
	gd->player_img_up = mlx_xpm_file_to_image(gd->mlx,
			gd->player_img_up_path, &gd->res, &gd->res);
	gd->player_img_right = mlx_xpm_file_to_image(gd->mlx,
			gd->player_img_right_path, &gd->res, &gd->res);
	gd->player_img_down = mlx_xpm_file_to_image(gd->mlx,
			gd->player_img_down_path, &gd->res, &gd->res);
	gd->player_img_left = mlx_xpm_file_to_image(gd->mlx,
			gd->player_img_left_path, &gd->res, &gd->res);
}

void	initialize_all_images(t_game_data *gd)
{
	initialize_map_images(gd);
	initialize_enemy_images(gd);
	initialize_player_images(gd);
}
