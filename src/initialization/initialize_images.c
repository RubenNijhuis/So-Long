/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_images.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 16:13:41 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/24 14:10:35 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/*
 * Initializes all images
*/
void	initialize_map_images(t_game_data *gd)
{
	gd->textures.empty_space_img = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			SPACE_IMG_PATH, &gd->res, &gd->res);
	gd->textures.wall_img = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			WALL_IMG_PATH, &gd->res, &gd->res);
	gd->textures.collectible_img = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			COLLECTIBLE_IMG_PATH, &gd->res, &gd->res);
	gd->textures.map_exit_img = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			MAP_EXIT_IMG_PATH, &gd->res, &gd->res);
}
void	initialize_player_images(t_game_data *gd)
{
	gd->player.player_img_up = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			PLAYER_DIR_UP, &gd->res, &gd->res);
	gd->player.player_img_right = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			PLAYER_DIR_RIGHT, &gd->res, &gd->res);
	gd->player.player_img_down = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			PLAYER_DIR_DOWN, &gd->res, &gd->res);
	gd->player.player_img_left = mlx_xpm_file_to_image(gd->mlx_inst.mlx,
			PLAYER_DIR_LEFT, &gd->res, &gd->res);
}

void	initialize_all_images(t_game_data *gd)
{
	initialize_map_images(gd);
	initialize_player_images(gd);
}
