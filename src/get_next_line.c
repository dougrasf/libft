/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:36:17 by dofranci          #+#    #+#             */
/*   Updated: 2022/08/04 19:30:52 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_content(int fd, char *content)
{
	char	*buff;
	int		valueread;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (NULL);
	valueread = 1;
	while (ft_strchr(content, '\n') == 0 && valueread != 0)
	{
		valueread = read(fd, buff, BUFFER_SIZE);
		if (valueread == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[valueread] = '\0';
		content = ft_strjoin(content, buff);
	}
	free(buff);
	return (content);
}

static char	*get_line(char *content)
{
	char	*line;
	int		index;

	index = 0;
	while (content[index] && content[index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	index = 0;
	while (content[index] && content[index] != '\n')
	{
	line[index] = content[index];
	index++;
	}
	if (content[index] == '\n')
	{
		line[index] = content[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

static char	*get_rest(char *content)
{
	int		index;
	int		count;
	char	*rest;

	index = 0;
	while (content[index] && content[index] != '\n')
		index++;
	if (!content[index])
	{
		free(content);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(content) - index + 1));
	if (!rest)
		return (0);
	index++;
	count = 0;
	while (content[index])
		rest[count++] = content[index++];
	rest[count] = '\0';
	free(content);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	content = get_content(fd, content);
	if (!content)
		return (0);
	line = get_line(content);
	content = get_rest(content);
	return (line);
}
