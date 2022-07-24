/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 13:24:12 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/07/24 14:28:16 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

#include <stdint.h>
#include <stdio.h>

/*
 * Renders appropriate image based on character
*/
void	render_image(char type, uint32_t row, uint32_t column, t_game_data *gd)
{
	void	*image;

	image = NULL;
	if (type == '0')
		image = gd->textures.empty_space_img;
	else if (type == '1')
		image = gd->textures.wall_img;
	else if (type == 'C')
		image = gd->textures.collectible_img;
	else if (type == 'E')
		image = gd->textures.map_exit_img;
	mlx_put_image_to_window(gd->mlx_inst.mlx, gd->mlx_inst.win, image,
		IMG_RES * column, IMG_RES * row);
}

/*
 * Goes through each character and renders the image
*/
int	render_map(t_game_data *gd, uint32_t row, uint32_t column)
{
	render_image('0', row, column, gd);
	render_image(gd->map.map[row][column], row, column, gd);
	if (gd->goal.amount_collectibles == 0)
		gd->goal.allowed_to_exit = 1;
	return (0);
}

/*
 * Starting point of the game rendering
*/
int	render_game(t_game_data *gd)
{
	go_through_map(gd, render_map);
	render_player(&gd->player, &gd->mlx_inst);
	gd->mlx_inst.total_frames++;
	return (0);
}

/*
 * Initialize mlx and add the hooks for interactivity
*/
void	render(t_game_data *gd)
{
	initialize_game(gd);
	initialize_all_images(gd);
	mlx_key_hook(gd->mlx_inst.win, key_hook, gd);
	mlx_loop_hook(gd->mlx_inst.mlx, render_game, gd);
	mlx_loop(gd->mlx_inst.mlx);
}
