/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:04 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:53:06 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

double	ft_complex_sqrnorm(t_complex c)
{
	double	a;
	double	b;

	a = c.r * c.r;
	b = c.i * c.i;
	return (a + b);
}

t_complex	ft_complex_inv(t_complex num, t_complex den)
{
	t_complex	inv;
	t_complex	ret;

	inv.r = den.r;
	inv.i = den.i * -1;
	num = ft_complex_mult(num, inv);
	den = ft_complex_mult(den, inv);
	ret.r = 0;
	ret.i = 0;
	if (den.r != 0)
	{
		ret.r = num.r / den.r;
		ret.i = num.i / den.r;
	}
	return (ret);
}

float	ft_complex_norm(t_complex c)
{
	return (c.r * c.r + c.i * c.i);
}

float	ft_complex_arg(t_complex c)
{
	return (atan2(c.i, c.r));
}
