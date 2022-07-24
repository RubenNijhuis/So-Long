/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 22:04:39 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/07/24 14:22:54 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

#include <stdlib.h>

/*
 * Renders correct player sprite based on direction
*/
void	render_player(t_player *player, t_mlx_inst *mlx_inst)
{
	void	*img;

	img = NULL;
	if (player->player_direction == up_dir)
		img = player->player_img_up;
	if (player->player_direction == right_dir)
		img = player->player_img_right;
	if (player->player_direction == down_dir)
		img = player->player_img_down;
	if (player->player_direction == left_dir)
		img = player->player_img_left;
	mlx_put_image_to_window(mlx_inst->mlx, mlx_inst->win, img,
		IMG_RES * player->player_x, IMG_RES * player->player_y);
}
