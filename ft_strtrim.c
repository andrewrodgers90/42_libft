/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:56:48 by arodgers          #+#    #+#             */
/*   Updated: 2023/09/06 18:08:08 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] && ft_ischarset(s1[start], set))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (end > start && ft_ischarset(s1[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (0);
	i = 0;
	while ((start + i) < end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
