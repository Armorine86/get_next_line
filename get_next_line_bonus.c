/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:36:28 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/25 13:37:52 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, int *bytes, char *string)
{
	char	*temp;

	temp = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!temp)
	{
		*bytes = -1;
		return (NULL);
	}
	while ((!string || !ft_memchr(string, '\n', ft_strlen(string)))
		&& (*bytes) != -1)
	{
		*bytes = read(fd, temp, BUFFER_SIZE);
		if (*bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[*bytes] = '\0';
		if (!*bytes)
			break ;
		string = ft_strjoin(string, temp);
	}
	free(temp);
	return (string);
}

char	*cat_string(int *bytes, char *line, char *string, int *i)
{
	if (!*bytes)
		return (ft_strdup(string));
	while (string[*i] != '\n')
		(*i)++;
	line = malloc(((*i) + 1) * sizeof(char));
	if (!line)
	{
		*bytes = -1;
		return (NULL);
	}
	ft_strlcpy(line, string, (*i));
	*bytes = 1;
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*string[MAX_OPEN];
	int			bytes;
	int			i;

	i = 0;
	bytes = 1;
	if (!line || (fd < 0 || 256 <= fd) || BUFFER_SIZE <= 0)
		return (-1);
	string[fd] = read_line(fd, &bytes, string[fd]);
	if (bytes == -1)
		return (bytes);
	line[0] = cat_string(&bytes, line[0], string[fd], &i);
	if (!string[fd])
		return (bytes);
	ft_strlcpy(string[fd], &string[fd][i + 1], ft_strlen(&string[fd][i + 1]));
	if (!bytes)
	{
		free(string[fd]);
		string[fd] = NULL;
	}
	return (bytes);
}
