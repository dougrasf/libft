/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:07:22 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/15 03:59:27 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	space;

	space = nmemb * size;
	if (nmemb != 0 && space / size != nmemb)
		return (NULL);
	p = (void *)malloc(space);
	if (p == 0)
	{
		return (0);
	}
	ft_bzero(p, space);
	return (p);
}
