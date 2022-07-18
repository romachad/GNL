/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:34:42 by romachad          #+#    #+#             */
/*   Updated: 2022/07/18 04:15:05 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
//char	*ft_strjoin2(char *s1, char const *s2);
//void	ft_bzero(void *s, size_t n);
//char	*ft_strjoin_n(char *s1, char const *s2, size_t size);
//size_t	ft_strlcat(char *dest, const char *src, size_t size);
