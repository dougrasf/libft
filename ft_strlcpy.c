/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:15:33 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/14 20:02:58 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[count] != '\0' && count + 1 < size)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}
