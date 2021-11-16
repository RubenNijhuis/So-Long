/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/16 14:30:03 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx.h"
#include "../include/so_long.h"
#include "../include/libft.h"
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

int	main(int argc, char *argv[])
{
	struct s_game_data	*game_data;
	struct s_game_state	game_state;
	/*
		validate data
	*/
	(void)argc;
	validate_map(argv[1], game_data);

	printf("%s", game_data->map[0]);
	/*
		render data
	*/

	/*
		user data
	*/

	/*
		exit strat
	*/
	// void	*mlx;
	// void	*mlx_win;
	// char	*pepe;
	// int		honderd = 300;
	// char	*relative_path = "./assets/imgs/pep.xpm";
	// int*	height = &honderd; 
	// printf("%s", map[0]);
	// if (validate_args())
	// 	checkout("")
	// if (validate_map() != 1)
	// 	return 
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// pepe = mlx_xpm_file_to_image(mlx, relative_path, height, height);
	// mlx_put_image_to_window(mlx, mlx_win, pepe, 0, 0);
	// mlx_loop(mlx);
	return (0);
}
