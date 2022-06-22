/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:17:32 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/16 14:54:31 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;

	size = ft_strlen(s1);
	if (s1 == 0 || set == 0)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (size && ft_strchr(set, s1[size]))
		size--;
	return (ft_substr(s1, 0, size + 1));
}
