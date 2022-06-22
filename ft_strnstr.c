/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:16:48 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/16 00:10:32 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlesize;

	littlesize = ft_strlen(little);
	if (littlesize == 0)
		return ((char *)big);
	while (*big && len >= littlesize)
	{
		if ((ft_strncmp(big, little, littlesize) == 0))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
