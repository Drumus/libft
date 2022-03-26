/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibanez- <mibanez-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:23:27 by mibanez-          #+#    #+#             */
/*   Updated: 2022/03/22 18:42:10 by mibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*punt;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	punt = malloc(sizeof(char) * len + 1);
	if (!punt)
		return (0);
	while (s[i])
	{
		punt[i] = f(i, s[i]);
		i++;
	}
	punt[i] = '\0';
	return (punt);
}
