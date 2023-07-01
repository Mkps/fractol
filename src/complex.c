/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:49:12 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:49:14 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

t_complex	ft_complex_pow(t_complex c1, int pow)
{
	t_complex	tmp;

	if (pow <= 0)
	{
		tmp.r = 1;
		tmp.i = 0;
	}
	else if (pow == 1)
		return (c1);
	tmp = c1;
	pow--;
	while (pow)
	{
		tmp = ft_complex_mult(tmp, c1);
		pow--;
	}
	return (tmp);
}

t_complex	ft_complex_create(double real, double imaginary)
{
	t_complex	ret;

	ret.r = real;
	ret.i = imaginary;
	return (ret);
}
