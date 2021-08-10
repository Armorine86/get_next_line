/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:10:53 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/25 13:22:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		new[i] = *s2;
		s2++;
		i++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		i;
	int		src_len;

	i = 0;
	src_len = ft_strlen(src);
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy == NULL)
		return (NULL);
	while (i < src_len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size == 0)
	{
		dst[i] = '\0';
		return (ft_strlen(src));
	}
	while (i <= size - 1)
	{
		dst[i] = src[i];
		if (*src == '\0')
			break ;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
