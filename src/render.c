/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 13:24:12 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/21 11:04:50 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>

/*
 * Renders appropriate image based on character
*/
void	render_image(char type, int row, int column, t_game_data *gd)
{
	void	*image;

	if (type == '0' || type == 'P')
		image = gd->empty_space_img;
	if (type == '1')
		image = gd->wall_img;
	if (type == 'C')
		image = gd->collectible_img;
	if (type == 'E')
		image = gd->map_exit_img;
	mlx_put_image_to_window(gd->mlx, gd->win, image,
		gd->res * column, gd->res * row);
}

/*
 * Goes through each character and renders the image
*/
int	render_map(t_game_data *gd, int row, int column)
{
	render_image('0', row, column, gd);
	render_image(gd->map[row][column], row, column, gd);
	render_player(gd);
	if (gd->amount_collectibles == 0)
		gd->allowed_to_exit = 1;
	return (0);
}

/*
 * Starting point of the game rendering
*/
int	render_game(t_game_data *gd)
{
	go_through_map(gd, render_map);
	render_player(gd);
	// render_enemies(gd);
	gd->total_frames++;
	return (0);
}

/*
 * General create window
*/
void	*create_window(t_game_data *gd)
{
	void	*window;

	window = mlx_new_window(gd->mlx, gd->map_width * gd->res,
			gd->map_height * gd->res, gd->name);
	return (window);
}

/*
 * Initialize mlx and add the hooks for interactivity
*/
void	render(t_game_data *gd)
{
	initialize_game(gd);
	initialize_images_data(gd);
	initialize_player_data(gd);
	mlx_key_hook(gd->win, key_hook, gd);
	mlx_loop_hook(gd->mlx, render_game, gd);
	mlx_loop(gd->mlx);
}
