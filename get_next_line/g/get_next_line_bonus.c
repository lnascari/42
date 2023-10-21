/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:20:37 by lnascari          #+#    #+#             */
/*   Updated: 2022/12/02 10:24:38 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*ft_read(char *s, int fd)
{
	char	*tmp;
	int		check;

	check = 1;
	tmp = ft_calloc(1, BUFFER_SIZE + 1);
	if (!s)
		s = ft_calloc(1, 1);
	while (check > 0 && !ft_strchr(s, '\n'))
	{
		check = read(fd, tmp, BUFFER_SIZE);
		tmp[check] = '\0';
		s = ft_strjoin(s, tmp);
	}
	free(tmp);
	return (s);
}

static char	*new_str(char *s)
{
	int		size;
	int		i;
	char	*str;
	char	*tmp;

	if (!ft_strchr(s, '\n'))
	{
		free(s);
		return (0);
	}
	tmp = ft_strchr(s, '\n') + 1;
	size = ft_strlen(tmp);
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (0);
	i = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	free(s);
	return (str);
}

static char	*get_line(char *s)
{
	int		size;
	int		i;
	char	*line;

	size = 0;
	if (!s[size])
		return (0);
	while (s[size] && s[size] != '\n')
		size++;
	if (s[size] == '\n')
		size++;
	line = ft_calloc(size + 1, 1);
	if (!line)
		return (0);
	i = -1;
	while (++i < size)
		line[i] = s[i];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s[4096];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	s[fd] = ft_read(s[fd], fd);
	if (!s[fd])
		return (0);
	line = get_line(s[fd]);
	s[fd] = new_str(s[fd]);
	return (line);
}
