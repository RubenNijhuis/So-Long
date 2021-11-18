/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 16:13:41 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/18 16:49:51 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/mlx.h"

void	initialize_game_data(struct s_game_data *gd)
{
	int		*sizeptr;
	int		size;

	size = 32;
	sizeptr = &size;
	gd->name = "Danger Dungeon";
	gd->empty_space_img_path = "assets/imgs/small.xpm";
	gd->wall_img_path = "assets/imgs/small.xpm";
	gd->collectible_img_path = "assets/imgs/small.xpm";
	gd->map_exit_img_path = "assets/imgs/small.xpm";
	gd->player_img_path = "assets/imgs/small.xpm";
	gd->empty_space_img = mlx_xpm_file_to_image(gd->mlx,
			gd->empty_space_img_path, sizeptr, sizeptr);
	gd->wall_img = mlx_xpm_file_to_image(gd->mlx,
			gd->wall_img_path, sizeptr, sizeptr);
	gd->collectible_img = mlx_xpm_file_to_image(gd->mlx,
			gd->collectible_img_path, sizeptr, sizeptr);
	gd->map_exit_img = mlx_xpm_file_to_image(gd->mlx,
			gd->map_exit_img_path, sizeptr, sizeptr);
	gd->player_img = mlx_xpm_file_to_image(gd->mlx,
			gd->player_img_path, sizeptr, sizeptr);
}
