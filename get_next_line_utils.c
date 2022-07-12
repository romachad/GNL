/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:32:55 by romachad          #+#    #+#             */
/*   Updated: 2022/07/10 05:18:50 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	mem_size;

	if (nmemb == 0 || size == 0)
		return (0);
	mem_size = nmemb * size;
	if (mem_size / nmemb != size)
		return (0);
	mem = malloc(mem_size);
	if (!mem)
		return (0);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*replace;

	if (!s)
		return ;
	replace = (char *) s;
	i = 0;
	while (i < n)
	{
		replace[i] = 0;
		i++;
	}
}

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

char	*ft_strjoin_n(char *s1, char const *s2, size_t size)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (size_s2 > size)
		size_s2 = size;
	//joined = malloc((size_s1 + size + 1) * sizeof(char));
	joined = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!joined)
		return (0);
	i = 0;
	//while (i < (size_s1 + size + 1))
	while (i < (size_s1 + size_s2 + 1))
	{
		if (i < size_s1)
			joined[i] = s1[i];
		else
			joined[i] = s2[i - size_s1];
		i++;
	}
	joined[i] = 0;
	free (s1);
	return (joined);
}

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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_d;
	size_t	size_s;
	size_t	i;

	if (!src || !dest)
		return (0);
	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	if (size < size_d || size == 0)
		return (size_s + size);
	i = 0;
	while (((size_d + i) < (size - 1)) && src[i] != 0)
	{
		dest[size_d + i] = src[i];
		i++;
	}
	dest[size_d + i] = 0;
	if (dest <= src && (dest + size) >= src)
		return (size_d + size_s + i);
	else
		return (size_d + size_s);
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
