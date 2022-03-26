/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibanez- <mibanez-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:57:04 by mibanez-          #+#    #+#             */
/*   Updated: 2022/03/23 15:15:02 by mibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	n_digits(int n)
{
	int	digits;

	digits = 0;
	while (n > 9)
	{
		n = (n - (n % 10)) / 10;
		digits++;
	}
	return (digits);
}

static char	*rellenator(int digits, int sign, int trash, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(digits + 1, 1);
	if (!str)
		return (0);
	while (n > 9)
	{
		str[digits - i - 1] = ((n % 10) + '0');
		n = (n - (n % 10)) / 10;
		i++;
	}
	if (sign == -1)
		str[0] = '-';
	str[digits - i - 1] = ((n % 10) + '0');
	if (trash == 1)
		str[digits - 1] += 1;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		sign;
	int		trash;

	trash = 0;
	digits = 1;
	sign = 1;
	if (n == -2147483648)
	{
		n += 1;
		trash = 1;
	}
	if (n < 0)
	{
		sign = -1;
		n *= sign;
		digits += 1;
	}
	digits += n_digits(n);
	str = rellenator(digits, sign, trash, n);
	return (str);
}
