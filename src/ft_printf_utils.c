/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:17:07 by dofranci          #+#    #+#             */
/*   Updated: 2022/09/13 21:23:23 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_putnbr2(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
	{
		ret += ft_putnbr2(n / 10);
		ret += ft_putchar(n % 10 + '0');
	}
	else
		ret += ft_putchar(n + '0');
	return (ret);
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		ret++;
		n *= -1;
	}
	return (ft_putnbr2(n) + ret);
}

int	ft_putptr2(unsigned long int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += ft_putptr2(n / 16);
		ret += ft_putptr2(n % 16);
	}
	else if (n <= 9)
		ret += ft_putchar(n + '0');
	else
		ret += ft_putchar(n - 10 + 'a');
	return (ret);
}

int	ft_putptr(unsigned long long int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		ret += write(1, "(nil)", 5);
	else
	{
		ret += write(1, "0x", 2);
		ret += ft_putptr2(n);
	}
	return (ret);
}

int	ft_putx(unsigned int n, char conv)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += ft_putx(n / 16, conv);
		ret += ft_putx(n % 16, conv);
	}
	else if (n <= 9)
		ret += ft_putchar(n + '0');
	else if (conv == 'x')
		ret += ft_putchar(n - 10 + 'a');
	else if (conv == 'X')
		ret += ft_putchar(n - 10 + 'A');
	return (ret);
}
