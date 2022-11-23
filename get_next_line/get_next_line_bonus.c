/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:20:37 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/23 17:25:48 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

static int	ft_check(char *s, int b)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] != '\n')
	{
		if (b && s[i] == 0)
		{
			if (i < BUFFER_SIZE - 1)
				return (0);
			else
				return (1);
		}
		if (s[i] == 0 && !b)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_read(char **s, int fd)
{
	char	*tmp;
	int		b;

	b = ft_check(*s, 0);
	while (b)
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!tmp || read(fd, tmp, BUFFER_SIZE) == -1)
			return (0);
		if (tmp[0] == 0)
			return (0);
		b = ft_check(tmp, 1);
		if (!*s)
			*s = tmp;
		else
			*s = ft_strjoin(*s, tmp);
		if (!*s)
			return (0);
	}
	return (1);
}

static int	ft_size(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == 0)
			return (i * -1);
		i++;
	}
	return (i);
}

static char	*get_line(char **s)
{
	int		size;
	char	*line;

	size = ft_size(*s);
	if (size <= 0)
	{
		line = ft_strlcpy(*s, size * -1 + 2, *s);
		if (!line)
			return (0);
		*s = ft_calloc(2, 1);
		if (!*s)
			return (0);
	}
	else
	{
		line = ft_strlcpy(*s, size + 2, 0);
		*s = ft_strlcpy(*s + (size + 1), ft_strlen(*s) - size + 1, *s);
		if (!line || !*s)
			return (0);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s[FOPEN_MAX];

	if ((s[fd] && s[fd][0] == 0) || BUFFER_SIZE <= 0 ||
		fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!ft_read(&s[fd], fd))
		return (0);
	return (get_line(&s[fd]));
}
