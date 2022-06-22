/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:13:35 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/16 16:24:24 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (unsigned char) c)
		{
			return ((char *)s + count);
		}
		count++;
	}
	if (s[count] == (unsigned char) c)
		return ((char *)s + count);
	return (NULL);
}
