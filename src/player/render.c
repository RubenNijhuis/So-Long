/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 22:04:39 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/21 11:12:04 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

/*
 * Renders correct player sprite based on direction
*/
void	render_player(t_game_data *gd)
{
	void	*img;

	if (gd->player_direction == 1)
		img = gd->player_img_up;
	if (gd->player_direction == 2)
		img = gd->player_img_right;
	if (gd->player_direction == 3)
		img = gd->player_img_down;
	if (gd->player_direction == 4)
		img = gd->player_img_left;
	mlx_put_image_to_window(gd->mlx, gd->win, img,
		gd->res * gd->player_x, gd->res * gd->player_y);
}
