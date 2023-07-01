/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:51:52 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:51:54 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

void	init_img(t_vars *vars)
{
	int	bpp;
	int	line_length;
	int	endian;

	vars->img.img = mlx_new_image(vars->mlx,
			vars->w_data.width, vars->w_data.height);
	if (!vars->img.img)
	{
		ft_putstr_fd("Error creating image...\nExiting\n", 2);
		ft_mlx_exit(vars);
	}
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&bpp, &line_length, &endian);
	vars->img.line_length = line_length;
	vars->img.bits_per_pixel = bpp;
	vars->img.endian = endian;
}

void	ft_mlx_exit(t_vars *vars)
{
	int	errcode;

	errcode = 0;
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	else
		errcode++;
	if (vars->w_ptr)
		mlx_destroy_window(vars->mlx, vars->w_ptr);
	else
		errcode++;
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(errcode);
}

static void	fractal_picker_expanded(int keycode, t_vars *vars)
{
	if (keycode == '4')
	{
		vars->color = 9;
		vars->fractal = ft_newton;
	}
	else if (keycode == '5')
	{
		vars->color = 0;
		vars->power = 2;
		vars->fractal = ft_burning_ship;
	}
	else if (keycode == '6')
	{
		vars->color = 3;
		vars->offset_x = -1;
		vars->fractal = ft_nova;
	}
}

void	ft_fractal_picker(int keycode, t_vars *vars)
{
	vars->offset_x = 0;
	if (keycode == '1')
	{
		vars->color = 0;
		vars->fractal = ft_mandelbrot;
	}
	else if (keycode == '2')
	{
		ft_julia_set(vars);
		vars->color = 2;
		vars->fractal = ft_julia;
	}
	else if (keycode == '3')
	{
		vars->color = 7;
		vars->power = 4;
		vars->fractal = ft_power;
	}
	else
		fractal_picker_expanded(keycode, vars);
}
