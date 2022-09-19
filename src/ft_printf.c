/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:09:49 by dofranci          #+#    #+#             */
/*   Updated: 2022/09/13 21:23:16 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	if (!s)
		s = "(null)";
	while (s[++i])
	{
		write(1, &s[i], 1);
		ret++;
	}
	return (ret);
}

int	ft_printer(char conv, va_list *ap)
{
	int	ret;

	ret = 0;
	if (conv == '%')
		ret += write(1, "%", 1);
	if (conv == 'c')
		ret += ft_putchar(va_arg(*ap, int));
	if (conv == 's')
		ret += ft_putstr(va_arg(*ap, char *));
	if (conv == 'd' || conv == 'i')
		ret += ft_putnbr(va_arg(*ap, int));
	if (conv == 'u')
		ret += ft_putnbr2(va_arg(*ap, unsigned int));
	if (conv == 'p')
		ret += ft_putptr(va_arg(*ap, unsigned long int));
	if (conv == 'x' || conv == 'X')
		ret += ft_putx(va_arg(*ap, unsigned int), conv);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	va_list	ap;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		if (format[i] == '%')
		{
			i++;
			ret += ft_printer(format[i], &ap);
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
