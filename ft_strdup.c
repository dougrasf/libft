/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:14:20 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/16 02:13:06 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		count;

	count = 0;
	dest = (char *)malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (dest == 0)
		return (0);
	while (s[count] != 0)
	{
		dest[count] = s[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
