/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 11:40:22 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/21 14:15:00 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

/*
 * Renders correct enemy sprite based on direction
*/
void	render_enemies(t_game_data *gd)
{
void	*img;
	int		i;

	i = 0;
	while (i < gd->amount_enemies)
	{
		if (gd->enemies[amount_enemies - 1]->direction == 1)
			img = gd->enemy_img_up;
		if (gd->enemies[amount_enemies - 1]->direction == 2)
			img = gd->enemy_img_right;
		if (gd->enemies[amount_enemies - 1]->direction == 3)
			img = gd->enemy_img_down;
		if (gd->enemies[amount_enemies - 1]->direction == 4)
			img = gd->enemy_img_left;
		i++;
	}
	mlx_put_image_to_window(gd->mlx, gd->win, img,
		gd->res * gd->player_x, gd->res * gd->player_y);
}