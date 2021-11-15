/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/15 13:47:43 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include "../libs/LibFT/src/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	printf("%i", ft_isascii('a'));
	// void	*mlx;
	// void	*mlx_win;
	// // t_data	img;

	// // char	*pepe;
	// // int		honderd = 300;
	// // int*	height = &honderd;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// // img.img = mlx_new_image(mlx, 1920, 1080);
	// // pepe = mlx_xpm_file_to_image(mlx, "./pep.xpm", height, height);
	// // mlx_put_image_to_window(mlx, mlx_win, pepe, 0, 0);
	// mlx_loop(mlx);
}
