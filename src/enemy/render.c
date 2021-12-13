/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 11:40:22 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/12/13 16:36:03 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <stdio.h>

/*
 * Renders correct enemy sprite based on direction
*/
void	render_enemies(t_game_data *gd)
{
	void	*img;
	int		i;
	t_enemy	*enemy;

	i = 0;
	while (i < gd->amount_enemies)
	{
		enemy = gd->enemies[i];
		if (enemy->direction == 1)
			img = gd->enemy_img_up;
		if (enemy->direction == 2)
			img = gd->enemy_img_right;
		if (enemy->direction == 3)
			img = gd->enemy_img_down;
		if (enemy->direction == 4)
			img = gd->enemy_img_left;
		mlx_put_image_to_window(gd->mlx, gd->win, img,
			gd->res * enemy->position_x, gd->res * enemy->position_y);
		i++;
	}
}
