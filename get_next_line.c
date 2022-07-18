/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:40:34 by romachad          #+#    #+#             */
/*   Updated: 2022/07/18 04:11:39 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	joined = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!joined)
		return (0);
	i = 0;
	while (i < (size_s1 + size_s2 + 1))
	{
		if (i < size_s1)
			joined[i] = s1[i];
		else
			joined[i] = s2[i - size_s1];
		i++;
	}
	free (s1);
	return (joined);
}

static char	*read_line(int fd, char *buff_read)
{
	ssize_t	bytes;
	char	*str;

	//str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//str = calloc((BUFFER_SIZE + 1), sizeof(char));
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	bytes = BUFFER_SIZE;
	while (!(ft_strchr(buff_read, '\n')) && bytes > 0)
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

static char	*adjust_line(char *buff_read)
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

static char	*adjust_buffer(char *buff_read)
{
	size_t	i;
	size_t	sizeb;
	char	*swap;

	i = 0;
	while (buff_read[i] && buff_read[i] != '\n')
		i++;
	if (buff_read[i] == '\n')
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
	char		*line;

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
