/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 13:24:12 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/20 01:12:42 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>

void	render_image(char type, int row, int column, struct s_game_data *gd)
{
	void	*image;
	int		size;

	size = 32;
	if (type == '0' || type == 'P')
		image = gd->empty_space_img;
	if (type == '1')
		image = gd->wall_img;
	if (type == 'C')
		image = gd->collectible_img;
	if (type == 'E')
		image = gd->map_exit_img;
	mlx_put_image_to_window(gd->mlx, gd->win, image, 32 * column, 32 * row);
}

int	render_map(struct s_game_data *gd)
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
			column++;
		}
		column = 0;
		row++;
	}
	gd->total_frames++;
	if (gd->total_frames % 90 == 0)
		printf("%lu\n", gd->total_frames);
	render_player(gd);
	return (0);
}

void	*create_window(struct s_game_data *gd)
{
	void	*window;

	window = mlx_new_window(gd->mlx, gd->map_width * 32,
			gd->map_height * 32, gd->name);
	return (window);
}

void	render(struct s_game_data *gd)
{
	gd->player_total_moves = 0;
	gd->key_up = 13;
	gd->key_down = 1;
	gd->key_right = 2;
	gd->key_left = 0;
	gd->total_frames = 0;
	gd->mlx = mlx_init();
	initialize_game_data(gd);
	gd->win = create_window(gd);
	mlx_key_hook(gd->win, key_hook, gd);
	mlx_loop_hook(gd->mlx, render_map, gd);
	mlx_loop(gd->mlx);
}
