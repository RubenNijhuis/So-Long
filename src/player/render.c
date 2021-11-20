/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 22:04:39 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/20 01:12:00 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

void	render_player(struct s_game_data *gd)
{
	mlx_put_image_to_window(gd->mlx, gd->win,
		gd->player_img, 32 * gd->player_x, 32 * gd->player_y);
}
