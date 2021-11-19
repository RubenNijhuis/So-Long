/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 13:24:12 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/19 13:05:42 by rnijhuis      ########   odam.nl         */
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
			render_image('0', row, column, gd);
			render_image(gd->map[row][column], row, column, gd);
			column++;
		}
		column = 0;
		row++;
	}
}

void	*create_window(struct s_game_data *gd)
{
	void	*window;

	window = mlx_new_window(gd->mlx, gd->map_width * 32,
			gd->map_height * 32, gd->name);
	return (window);
}

int	render_next_frame(struct s_game_data *gd)
{
	render_map(gd);
}

void	render(struct s_game_data *gd)
{
	gd->mlx = mlx_init();
	initialize_game_data(gd);
	gd->mlx_win = create_window(gd);
	render_map(gd);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(mlx, render_next_frame, YourStruct);

	mlx_loop(gd->mlx);
}
