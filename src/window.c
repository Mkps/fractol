/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:52:03 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:52:05 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

void	ft_pos_zoom(int x, int y, t_vars *vars)
{
	double	width;
	double	height;
	double	offwidth;
	double	offheight;

	width = (float)(vars->w_data.width - x) / vars->w_data.width;
	width = 1 - width;
	offwidth = ft_lerp(-2.0 * vars->zoom, 2.0 * vars->zoom, width);
	vars->offset_x += offwidth;
	height = (float)(vars->w_data.height - y) / vars->w_data.height;
	height = 1 - height;
	offheight = ft_lerp(-2.0 * vars->zoom, 2.0 * vars->zoom, height);
	vars->offset_y += offheight;
}

void	ft_julia_set(t_vars *vars)
{
	if (vars->c.r == -0.77146)
		vars->c = ft_complex_create(0.18, -0.566667);
	else if (vars->c.r == 0.18)
		vars->c = ft_complex_create(-0.75, 0.0);
	else if (vars->c.r == -0.75)
		vars->c = ft_complex_create(-0.12, 0.75);
	else if (vars->c.r == -0.12)
		vars->c = ft_complex_create(-0.566667, 0.520000);
	else if (vars->c.r == -0.566667)
		vars->c = ft_complex_create(0.0, -1.0);
	else
		vars->c = ft_complex_create(-0.77146, -0.10119);
}

void	ft_key_movement(int key, t_vars *vars)
{
	double	offset;

	offset = 0.1 * vars->zoom;
	if (offset < 0.000000001)
		offset = 0.000000001;
	if (key == 'd' || key == 'D'
		|| key == 65363)
		vars->offset_x += offset;
	else if (key == 'a' || key == 'A'
		|| key == 65361)
		vars->offset_x -= offset;
	else if (key == 'w' || key == 'W'
		|| key == 65362)
		vars->offset_y -= offset;
	else if (key == 's' || key == 'S'
		|| key == 65364)
		vars->offset_y += offset;
	else if (key == 'x' || key == 'X')
		vars->zoom *= 0.5;
	else if (key == 'z' || key == 'Z')
		vars->zoom *= 1.5;
}

static void	ft_controls(int keycode, t_vars *vars)
{
	if (keycode == 'h' || keycode == 'H')
	{
		if (vars->is_menu_on == 1)
			vars->is_menu_on = 0;
		else
			vars->is_menu_on = 1;
	}
	else if (keycode == 'c' || keycode == 'C' || keycode == 65289)
	{
		if (vars->color != 9)
			vars->color++;
		if (vars->color > 7 && vars->color != 9)
			vars->color = 0;
	}
	else if (keycode == 32)
		vars->power++;
}

void	ft_window_controls(int keycode, t_vars *vars)
{
	if (keycode == 'u' || keycode == 'U')
		vars->iteration *= 2;
	else if (keycode == 'j' || keycode == 'J')
		vars->iteration *= 0.5;
	else if (keycode == 'o' || keycode == 'O')
		vars->resolution *= 0.5;
	else if (keycode == 'l' || keycode == 'L')
		vars->resolution *= 1.5;
	else if (keycode == 'b' || keycode == 'B')
		vars->smooth += 1;
	else if (keycode == 'n' || keycode == 'N')
		vars->smooth -= 1;
	else
		ft_controls(keycode, vars);
}
