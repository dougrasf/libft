/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:08:32 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/16 18:20:29 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		size++;
	}
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_brokenbr(char *str, size_t numbers,
						unsigned int n, unsigned int negative)
{
	str[numbers] = '\0';
	while (numbers > 0)
	{
		str[numbers - 1] = (n % 10) + '0';
		n /= 10;
		numbers--;
	}
	if (negative)
		str[numbers] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	negative;
	size_t			numbers;

	numbers = ft_nbrlen(n);
	negative = 0;
	str = malloc(sizeof (char) * (numbers + 1));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		negative = 1;
		n = n * -1;
	}
	return (ft_brokenbr(str, numbers, n, negative));
}
