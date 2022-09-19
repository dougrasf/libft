/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:16:35 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/14 19:22:07 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while ((s1[count] || s2[count]) && (count < n))
	{
		if (s1[count] != s2[count])
			return ((unsigned char) s1[count] - (unsigned char)s2[count]);
		count++;
	}
	return (0);
}
