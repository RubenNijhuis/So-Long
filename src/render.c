/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 13:24:12 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/18 16:51:56 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"
#include "../include/mlx.h"
#include <stdio.h>

// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	render_image(char type, int row, int column, struct s_game_data *gd)
{
	void	*image;
	int		*sizeptr;
	int		size;

	size = 32;
	sizeptr = &size;
	if (type == '0')
		image = gd->empty_space_img;
	if (type == '1')
		image = gd->wall_img;
	if (type == 'C')
		image = gd->collectible_img;
	if (type == 'E')
		image = gd->map_exit_img;
	if (type == 'P')
		image = gd->player_img;
	mlx_put_image_to_window(gd->mlx, gd->mlx_win, image, 32 * column, 32 * row);
}

void	render_map(struct s_game_data *gd)
{
	int		row;
	int		column;

	row = 0;
	column = 0;
	while (row < gd->map_height)
	{
		while (column < gd->map_width)
		{
			render_image(gd->map[row][column], row, column, gd);
			column++;
		}
		column = 0;
		row++;
	}
}

void	render(struct s_game_data *gd)
{
	// printf("%s", gd->player_img);
	gd->mlx = mlx_init();
	gd->mlx_win = mlx_new_window(gd->mlx, gd->map_width * 32, gd->map_height * 32, gd->name);
	render_map(gd);
	mlx_loop(gd->mlx);
}
