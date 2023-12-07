/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:48:08 by arodgers          #+#    #+#             */
/*   Updated: 2023/08/30 16:43:49 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}
	new = (char *)malloc(sizeof(char) * (j + 1));
	if (!new)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
