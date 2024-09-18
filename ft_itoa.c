/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:40:24 by arodgers          #+#    #+#             */
/*   Updated: 2023/11/06 17:52:43 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_length(long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	int		len;
	int		is_negative;

	num = n;
	len = nbr_length(num);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	is_negative = 0;
	if (num < 0)
	{
		result[0] = '-';
		num = num * -1;
		is_negative = 1;
	}
	result[len] = '\0';
	while (len > is_negative)
	{
		result[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (result);
}
