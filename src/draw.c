/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:49:25 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:49:45 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

int	ft_color_sin(t_vars *vars, int iter)
{
	iter = iter + 1 - (log(2) / vars->iteration) / log (2);
	if (!iter)
		return (0xFF000000);
	return (ft_color_int(255,
			sin(0.116 * iter + 4) * 230 + 25,
			sin(0.013 * iter + 2) * 255 + 25,
			sin(0.01 * iter + 1) * 230 + 25));
}

int	ft_color_hue(int iter)
{
	double	iter_d;

	if (!iter)
		return (0xFF000000);
	iter_d = iter;
	return (ft_color_hsv(3 * iter % 255, 0.5 * sin(iter_d * 0.015) + 0.5, 1.0));
}

void	ft_color(int iter, double x, double y, t_vars *vars)
{
	t_data	img;

	img = vars->img;
	x *= vars->w_data.width;
	y *= vars->w_data.height;
	if (vars->color == 0)
		ft_mlx_pixel_put(&img, x, y, ft_color_bs(vars, iter));
	if (vars->color == 1)
		ft_mlx_pixel_put(&img, x, y, ft_color_bb(vars, iter));
	if (vars->color == 2)
		ft_mlx_pixel_put(&img, x, y, ft_color_ra(vars, iter));
	if (vars->color == 3)
		ft_mlx_pixel_put(&img, x, y, ft_color_sin(vars, iter));
	if (vars->color == 4)
		ft_mlx_pixel_put(&img, x, y, ft_color_hue(iter));
	if (vars->color == 5)
		ft_mlx_pixel_put(&img, x, y, ft_color_br(vars, iter));
	if (vars->color == 6)
		ft_mlx_pixel_put(&img, x, y, ft_color_cr(vars, iter));
	if (vars->color == 7)
		ft_mlx_pixel_put(&img, x, y, ft_color_mono(vars, iter));
	if (vars->color == 9)
		ft_mlx_pixel_put(&img, x, y, ft_color_newton(iter));
}
