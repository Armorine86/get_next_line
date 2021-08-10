/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:11:32 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/25 13:33:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define MAX_OPEN 256

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *buf1, const char *buf2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*cat_string(int *res, char *line, char *save, int *i);
char	*read_line(int fd, int *res, char *save);

#endif
