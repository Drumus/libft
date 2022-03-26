/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibanez- <mibanez-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:06:38 by mibanez-          #+#    #+#             */
/*   Updated: 2022/03/22 16:57:43 by mibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = len;
	while (i > 0)
	{
		i--;
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
	}
	if ((unsigned char)c == '\0')
		return (&((char *)s)[len]);
	return (NULL);
}
