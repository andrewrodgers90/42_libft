/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:19:05 by arodgers          #+#    #+#             */
/*   Updated: 2023/09/02 14:03:18 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		i;
	char	arr[20];

	num = n;
	i = 0;
	if (0 == n)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	while (num > 0)
	{
		arr[i++] = (num % 10) + 48;
		num /= 10;
	}
	while (i > 0)
		write(fd, &arr[--i], 1);
}
