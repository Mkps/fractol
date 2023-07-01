/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:10 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:53:11 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

int	ft_mlx_destroy_hook(t_vars *vars)
{
	ft_mlx_exit(vars);
	return (0);
}

int	ft_mlx_key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307 || keycode == 27)
		ft_mlx_exit(vars);
	if (keycode >= 1 && keycode <= '6')
		ft_fractal_picker(keycode, vars);
	ft_key_movement(keycode, vars);
	ft_window_controls(keycode, vars);
	return (0);
}

int	ft_mlx_mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4)
	{
		ft_pos_zoom(x, y, vars);
		vars->zoom *= 0.5;
	}
	else if (keycode == 5)
		vars->zoom *= 1.5;
	return (0);
}
