/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:50:18 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:50:19 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

t_complex	ft_complex_div(t_complex c1, t_complex c2)
{
	t_complex	ret;

	ret.r = (c1.r * c2.r + c1.i * c2.i) / (c2.r * c2.r + c2.i * c2.i);
	ret.i = (-1 * c1.r * c2.i + c1.i * c2.r) / (c2.r * c2.r + c2.i * c2.i);
	return (ret);
}

t_complex	ft_complex_mult(t_complex c1, t_complex c2)
{
	t_complex	tmp;

	tmp.r = c1.r * c2.r - c1.i * c2.i;
	tmp.i = c1.r * c2.i + c2.r * c1.i;
	return (tmp);
}

t_complex	ft_complex_add(t_complex c1, t_complex c2)
{
	t_complex	tmp;

	tmp.r = c1.r + c2.r;
	tmp.i = c1.i + c2.i;
	return (tmp);
}

t_complex	ft_complex_sub(t_complex c1, t_complex c2)
{
	t_complex	tmp;

	tmp.r = c1.r - c2.r;
	tmp.i = c1.i - c2.i;
	return (tmp);
}
