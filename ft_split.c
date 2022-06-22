/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:13:23 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/22 01:22:56 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


//str = "passar no mercado hoje" 
//c = " "
//   012345\0
// 0 passar
// 1 no
// 2 mercado
// 3 hoje"
// NULL 

// **str == str[2]4] == "a" 

static size_t	ft_countwords(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (*s == '\0')
		return (0);
	if (c == 0)
		return (1);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static size_t	ft_free(char **str, size_t count)
{
	free(str[count]);
	while (count > 0)
	{
		free(str[count - 1]);
		count--;
	}
	free (str);
	return (0);
}

static char	**ft_putwords(const char *s, char c, char **str)
{
	size_t	count;
	size_t	index;

	count = 0;
	while (*s)
	{
		index = 0;
		while (s[index] != c && s[index] != '\0')
			index++;
		str[count] = (char *)malloc(sizeof(char) * (index + 1));
		if (str[count] == 0)
			ft_free(str, c);
		str[count][index] = '\0';
		while (index > 0)
		{
			str[count][index - 1] = s[index - 1];
			index--;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		count++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	words;

	words = ft_countwords(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (str == 0)
		return (0);
	while (*s && *s == c)
		s++;
	str = ft_putwords(s, c, str);
	str[words] = NULL;
	return (str);
}
