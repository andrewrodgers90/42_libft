/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:41:04 by arodgers          #+#    #+#             */
/*   Updated: 2023/10/24 19:02:53 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	max;

	max = -1;
	if (size && (count > (max / size)))
	{
		return (NULL);
	}
	new = malloc(count * size);
	if (!new)
	{
		return (0);
	}
	ft_bzero(new, count * size);
	return (new);
}
