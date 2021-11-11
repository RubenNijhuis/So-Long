/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 13:42:15 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/11 15:17:43 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./so_long.h"

int	main(void)
{
	void	*wnw;
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1000, 600, "shlong");
	mlx_loop(mlx);
}
