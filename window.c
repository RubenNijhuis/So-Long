/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 14:15:19 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/11 15:15:25 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"

void	create_window(void *mlx, void *wndw, int width, int height, char *title)
{
	mlx = mlx_init();
	wndw = mlx_new_window(mlx, width, height, title);
}
