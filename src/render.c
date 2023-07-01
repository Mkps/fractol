/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:52:13 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:52:15 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

// mlx_destroy_image(vars->mlx, vars->img.img);
// init_img(vars);
int	ft_mlx_render(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	init_img(vars);
	ft_fractal(vars->fractal, vars);
	mlx_put_image_to_window(vars->mlx, vars->w_ptr, vars->img.img, 0, 0);
	ft_menu(vars);
	return (0);
}

void	ft_mlx_fill(t_data img, int size_x, int size_y, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			ft_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
