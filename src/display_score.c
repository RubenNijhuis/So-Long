/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_score.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 01:54:10 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/22 02:00:01 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	display_score(t_game_data *gd)
{
	mlx_string_put(gd->mlx, gd->win, 10, 10, create_trgb(1, 0,0,0), ft_itoa(gd->amount_collectibles));
}