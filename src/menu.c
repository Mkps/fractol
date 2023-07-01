/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:52:36 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:52:38 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

void	ft_menu_print(t_vars *vars, int color)
{
	int	x;

	x = vars->w_data.width / 25;
	mlx_string_put(vars->mlx, vars->w_ptr, x, 10, color,
		"Press 'H' to close menu");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 35, color,
		"Move around with : WASD of Arrow Keys");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 60, color,
		"Zoom : [Mouse wheel or [Z]/[X]]");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 85, color,
		"Change Fractal : [1, 2, ...]");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 110, color,
		"Change Color : [TAB]");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 135, color,
		"Increase/Decrease current iteration : [U] [J]");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 160, color,
		"Increase/Decrease current resolution : [O] [L]");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 185, color,
		"Change Power of the fractal : [Space]");
	mlx_string_put(vars->mlx, vars->w_ptr, x, 210, color,
		"Exit : [ESCAPE]");
}

void	ft_menu(t_vars *vars)
{
	int	x;
	int	color;

	x = vars->w_data.width / 25;
	if (vars->color >= 0 && vars->color <= 3)
		color = 0xFFFFFFFF;
	else
		color = 0xFF000000;
	if (vars->is_menu_on == 0)
	{
		mlx_string_put(vars->mlx, vars->w_ptr, x, 10, color,
			"Press 'H' to open menu");
		return ;
	}
	else
		ft_menu_print(vars, color);
}
