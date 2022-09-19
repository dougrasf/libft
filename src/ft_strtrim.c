/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:17:32 by dofranci          #+#    #+#             */
/*   Updated: 2022/06/24 17:53:01 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>


char	*ft_strtrim(char const *s1, char const *set)
{
	/*
	size_t	size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[size - 1]))
		size--;
	return (ft_substr(s1, 0, size));


	size_t	size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[size]))
		size--;
	return (ft_substr(s1, 0, size + 1));
	*/
	size_t	size;
	
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
		size--;
	return (ft_substr((char *)s1, 0, size + 1));
}

int main(void)
{
	char str[]="    1WZhv8ROpsHGM LXxFDzBbgE ye3wa4gl pnJNPZOahXUWvw htPqaeo 1K7oDbgwdCWEB 1IK jpnP N6WfKvruniEgy7 QfqojIRbzUrl1 ";
	char expected[]="1WZhv8ROpsHGM LXxFDzBbgE ye3wa4gl pnJNPZOahXUWvw htPqaeo 1K7oDbgwdCWEB 1IK jpnP N6WfKvruniEgy7 QfqojIRbzUrl1";
	char set[]=" ";
	char *resultado;

	resultado = ft_strtrim(str, set);
	printf("str:%s\n", str);
	printf("expected:%s\n", expected);
	printf("resultado:%s\n", resultado);
	printf("strncmp:%i\n", strcmp(expected, resultado));

	printf("strlenexpected:%lu\n", strlen(expected));
	printf("strlenresultado:%lu\n", strlen(resultado));
	return(0);
}