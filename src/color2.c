/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:50:37 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:50:40 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

int	ft_color_br(t_vars *vars, int iter)
{
	double	s;

	(void)vars;
	s = (float)iter / 15;
	if (s > 1)
		s = 1.0;
	if (!iter)
		return (0xFF000000);
	return (ft_color_int(255, color_up(0, 223, s),
			color_up(0, 0, s), color_up(0, 0, s)));
}

int	ft_color_cr(t_vars *vars, int iter)
{
	double	s;

	(void)vars;
	s = (float)iter / vars->iteration;
	if (s > 1)
		s = 1.0;
	if (!iter)
		return (0xFFFFFFFF);
	return (ft_color_int(255, color_up(255, 255, s),
			color_up(255, 0, s), color_up(255, 0, s)));
}

int	ft_color_bs(t_vars *vars, int iter)
{
	double	s;
	double	s2;

	s = (float)iter / 20;
	s2 = (float)(iter) / ((float)vars->iteration / 4);
	if (s > 1)
		s = 1.0;
	if (s2 > 1)
		s2 = 1.0;
	if (!iter)
		return (0xFF000000);
	if (iter < 20)
		return (ft_color_int(255, color_up(0, 255, s),
				color_up(0, 230, s), color_up(30, 100, s)));
	return (ft_color_int(255, color_up(255, 255, s2),
			color_up(255, 98, s2), color_up(100, 0, s2)));
}

int	ft_color_newton(int iter)
{
	if (!iter)
		return (ft_color_int(255, 0, 0, 255));
	else if (iter < 0)
		return (ft_color_int(255, 255, 0, 0));
	else
		return (ft_color_int(255, 0, 255, 0));
}
