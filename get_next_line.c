/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:40:34 by romachad          #+#    #+#             */
/*   Updated: 2022/07/12 05:55:05 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


//#include <stdio.h>
char	*read_line(int fd, char *buff_read)
{
	ssize_t	bytes;
	char	*str;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	bytes = BUFFER_SIZE;
	while (!(ft_strchr(str, '\n')) && bytes > 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (str);
			return (NULL);
		}
		if (bytes)
		{
			str[bytes] = 0;
			buff_read = ft_strjoin2(buff_read, str);
		}
	}
	free (str);
	return (buff_read);
}

char	*adjust_line(char *buff_read)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buff_read[i] && buff_read[i] != '\n')
		i++;
	if (buff_read[i] && buff_read[i] == '\n' && buff_read[i + 1])
	{
		if (buff_read[i] == '\n')
			i++;
		line = ft_substr(buff_read, 0, i);
	}
	else
	{
		line = ft_strdup(buff_read);
	}
	if (!line)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*adjust_buffer(char *buff_read)
{
	size_t	i;
	size_t	sizeb;
	char	*swap;

	i = 0;
	while (buff_read[i] && buff_read[i] != '\n')
		i++;
	if (buff_read[i] == '\n' && buff_read[i + 1])
		i++;
	sizeb = ft_strlen(buff_read);
	if (sizeb - i > 0)
	{
		swap = ft_substr(buff_read, i, sizeb - i);
		free (buff_read);
		if (!swap)
		{
			free (swap);
			return (NULL);
		}
		return (swap);
	}
	free (buff_read);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff_read;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff_read = read_line(fd, buff_read);
	if (buff_read)
	{
		line = adjust_line(buff_read);
		buff_read = adjust_buffer(buff_read);
		return (line);
	}
	else
		return (NULL);
}
