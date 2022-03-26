/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibanez- <mibanez-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:35:16 by mibanez-          #+#    #+#             */
/*   Updated: 2022/03/22 16:33:22 by mibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		size;

	i = 0;
	j = 0;
	size = ft_strlen(needle);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (!haystack && needle)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i + size <= len && haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (j == size)
			return (&((char *)haystack)[i]);
		i++;
		j = 0;
	}
	return (0);
}
