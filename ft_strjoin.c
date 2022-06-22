/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:15:08 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/15 02:13:14 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		size1;
	int		size2;
	int		size3;

	size1 = ft_strlen(s1) + 1;
	size2 = ft_strlen(s2);
	size3 = size1 + size2;
	s3 = ft_calloc(size3, 1);
	ft_strlcpy(s3, s1, size1);
	ft_strlcat(s3, s2, size3);
	return (s3);
}
