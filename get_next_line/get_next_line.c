/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:20:37 by lnascari          #+#    #+#             */
/*   Updated: 2022/12/01 12:07:59 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	ft_read(char **s, int fd)
{
	char	*tmp;

	while (!*s || !ft_strchr(*s, '\n'))
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!tmp || read(fd, tmp, BUFFER_SIZE) == -1)
			return (0);
		if (tmp[0] == 0)
		{
			free(tmp);
			return (0);
		}
		if (!*s)
			*s = tmp;
		else
			*s = ft_strjoin(*s, tmp);
		if (!*s)
			return (0);
	}
	return (1);
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

static char	*get_line(char **s)
{
	int		size;
	int		i;
	char	*line;

	size = 0;
	while (*s[size] && *s[size] != '\n')
		size++;
	if (*s[size] == '\n')
		size++;
	line = ft_calloc(size + 1, 1);
	if (!line)
		return (0);
	i = -1;
	while (++i < size)
		line[i] = *s[i];
	*s = new_str(*s);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!ft_read(&s, fd))
		return (0);
	return (get_line(&s));
}
