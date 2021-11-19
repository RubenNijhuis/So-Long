/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 16:13:41 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/19 11:56:00 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

void	initialize_game_data(struct s_game_data *gd)
{
	int		size;

	size = 32;
	gd->name = "So Long";
	gd->empty_space_img_path = "assets/imgs/ground.xpm";
	gd->wall_img_path = "assets/imgs/wall.xpm";
	gd->collectible_img_path = "assets/imgs/collectible.xpm";
	gd->map_exit_img_path = "assets/imgs/exit.xpm";
	gd->player_img_path = "assets/imgs/small5.xpm";
	gd->empty_space_img = mlx_xpm_file_to_image(gd->mlx,
			gd->empty_space_img_path, &size, &size);
	gd->wall_img = mlx_xpm_file_to_image(gd->mlx,
			gd->wall_img_path, &size, &size);
	gd->collectible_img = mlx_xpm_file_to_image(gd->mlx,
			gd->collectible_img_path, &size, &size);
	gd->map_exit_img = mlx_xpm_file_to_image(gd->mlx,
			gd->map_exit_img_path, &size, &size);
	gd->player_img = mlx_xpm_file_to_image(gd->mlx,
			gd->player_img_path, &size, &size);
}
