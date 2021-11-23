/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_score.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 01:54:10 by rubennijhui   #+#    #+#                 */
/*   Updated: 2021/11/23 17:01:35 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

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
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	create_white_bg(t_game_data *gd)
{
	int		width;
	int		height;
	int		i;
	int		j;
	t_data	img;

	width = 120;
	height = 12;
	i = 0;
	j = 0;
	img.img = mlx_new_image(gd->mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i < width)
	{
		while (j < height)
		{
			my_mlx_pixel_put(&img, i, j, create_trgb(1, 255, 255, 255));
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(gd->mlx, gd->win, img.img, 0, 0);
}

void	display_score(t_game_data *gd)
{
	char	*str;

	str = ft_itoa(gd->player_total_moves);
	create_white_bg(gd);
	mlx_string_put(gd->mlx, gd->win, 2, 10,
		create_trgb(1, 0, 0, 0), "Total moves: ");
	mlx_string_put(gd->mlx, gd->win, 90, 10, create_trgb(1, 0, 0, 0),
		str);
	free(str);
}
