/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 22:04:39 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/20 09:00:52 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

void	render_player(struct s_game_data *gd)
{
	mlx_put_image_to_window(gd->mlx, gd->win,
		gd->player_img, gd->res * gd->player_x, gd->res * gd->player_y);
}
