/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 13:24:12 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/21 10:30:19 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>

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

int	render_map(t_game_data *gd)
{
	int		row;
	int		column;

	row = 0;
	column = 0;
	while (row < gd->map_height)
	{
		while (column < gd->map_width)
		{
			render_image('0', row, column, gd);
			render_image(gd->map[row][column], row, column, gd);
			render_player(gd);
			if (gd->amount_collectibles == 0)
				gd->allowed_to_exit = 1;
			column++;
		}
		column = 0;
		row++;
	}
	gd->total_frames++;
	render_player(gd);
	return (0);
}

void	*create_window(t_game_data *gd)
{
	void	*window;

	window = mlx_new_window(gd->mlx, gd->map_width * gd->res,
			gd->map_height * gd->res, gd->name);
	return (window);
}

void	render(t_game_data *gd)
{
	initialize_game(gd);
	initialize_images_data(gd);
	initialize_player_data(gd);
	mlx_key_hook(gd->win, key_hook, gd);
	mlx_loop_hook(gd->mlx, render_map, gd);
	mlx_loop(gd->mlx);
}
