/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:51:37 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/01 15:51:39 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_lp.h"

int	ft_getsign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		*i = 0;
		if (*str == '-')
			sign = -1;
	}
	return (sign);
}

void	atof_error(char *str, int i)
{
	if (str[i] != 0 || str[i - 1] == '.')
	{
		ft_putstr_fd("Incorrect parameter: ", 2);
		ft_putendl_fd(str, 2);
		ft_putstr_fd("Use ./fractol [Julia] [real] [imaginary]\n", 2);
		exit (1);
	}
}

double	ft_atof(char *str)
{
	int		sign;
	int		decimal;
	int		i;
	double	result;

	i = -1;
	sign = ft_getsign(str, &i);
	result = 0;
	while (ft_isdigit(str[++i]))
		result = result * 10 + (str[i] - '0');
	if (str[i] == '.')
		i++;
	decimal = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
		decimal++;
	}
	while (decimal--)
		result /= 10.0;
	result *= sign;
	atof_error(str, i);
	return (result);
}
