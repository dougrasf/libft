/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:10:31 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/16 00:14:34 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			count;

	count = 0;
	string = (unsigned char *)s;
	while (count < n)
	{
		if (string[count] == (unsigned char)c)
			return ((void *) string + count);
		count++;
	}
	return (0);
}
