/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:52:25 by arodgers          #+#    #+#             */
/*   Updated: 2023/09/11 13:48:53 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sign(int c)
{
	if (c == '-' || c == '+')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	ft_overflow_check(int sign)
{
	if (sign == 1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		sign_counter;
	int		i;
	long	num;

	sign = 1;
	num = 0;
	i = 0;
	sign_counter = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		sign_counter++;
	}
	while (ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	if (num < 0)
		return (ft_overflow_check(sign));
	if (sign_counter > 1)
		return (0);
	return (num * sign);
}
