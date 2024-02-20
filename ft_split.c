/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:50:01 by arodgers          #+#    #+#             */
/*   Updated: 2023/09/07 16:47:46 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		if (i == 0)
			break ;
		i--;
	}
	free(arr);
	return (NULL);
}

static char	**ft_allocatewords(char **arr, char const *s, char sep)
{
	char const	*temp;
	size_t		i;

	temp = s;
	i = 0;
	while (*temp)
	{
		while (*s == sep)
			s++;
		temp = s;
		while (*temp && *temp != sep)
			temp++;
		if (*temp == sep || *temp == '\0')
		{
			if (temp > s)
			{
				arr[i] = ft_substr(s, 0, temp - s);
				if (arr[i] == NULL)
					return (ft_freeall(arr, i));
				i++;
			}
			s = temp;
		}
	}
	return (arr);
}

static int	ft_wordcount(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != sep)
			s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	size = ft_wordcount(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (0);
	new[size] = NULL;
	return (ft_allocatewords(new, s, c));
}
