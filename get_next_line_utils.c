/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:32:55 by romachad          #+#    #+#             */
/*   Updated: 2022/07/20 01:53:32 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	else
		return (0);
}

char	*ft_strdup(const char *src)
{
	char	*new_str;
	int		size;
	int		i;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	new_str = malloc((size + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = src[i];
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	substr = ft_calloc((len + 1), sizeof(char));
	if (substr == 0)
		return (0);
	i = 0;
	while (s[i + start] && i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	mem_size;
	size_t	i;
	char	*replace;

	if (nmemb == 0 || size == 0)
		return (0);
	mem_size = nmemb * size;
	if (mem_size / nmemb != size)
		return (0);
	mem = malloc(mem_size);
	if (!mem)
		return (0);
	replace = (char *) mem;
	i = 0;
	while (i < mem_size)
	{
		replace[i] = 0;
		i++;
	}
	return (mem);
}
