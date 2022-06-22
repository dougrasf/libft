/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:15:17 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/14 19:36:01 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count1;
	size_t	count2;
	size_t	result;

	result = 0;
	count1 = 0;
	count2 = 0;
	while (dst[count1])
		count1++;
	while (src[result])
		result++;
	if (size <= count1)
		result = result + size;
	else
		result = result + count1;
	while (src[count2] && count1 + 1 < size)
	{
		dst[count1] = src[count2];
		count1++;
		count2++;
	}
	dst[count1] = 0;
	return (result);
}
