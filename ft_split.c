/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibanez- <mibanez-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:39:46 by mibanez-          #+#    #+#             */
/*   Updated: 2022/03/25 12:36:42 by mibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**rellenator(char **punt, char const *s, char c)
{
	int	i;
	int	start;
	int	j;

	j = 0;
	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			punt[j] = ft_substr(s, start, i - start + 1);
			j++;
		}
		i++;
	}
	punt[j] = NULL;
	return (punt);
}

char	**ft_split(char const *s, char c)
{
	char	**punt;

	punt = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!punt)
		return (0);
	return (rellenator(punt, s, c));
}
