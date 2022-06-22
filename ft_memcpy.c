/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:11:09 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/20 18:10:25 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (dest == 0 && src == 0)
		return (NULL);
	while (count < n)
	{
		((char *)dest)[count] = ((char *)src)[count];
		count++;
	}
	return (dest);
}
