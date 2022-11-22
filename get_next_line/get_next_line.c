/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:20:37 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/21 18:53:44 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	ft_len(char *s, int size)
{
	int	i;

	i = 0;
	while (s[i] != '\n' || s[i] != 0)
	{
		if (i == size - 1)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_read(char **s, int fd)
{
	char	*tmp;
	int		size;

	size = BUFFER_SIZE;
	*s = calloc(BUFFER_SIZE + 1, 1);
	if (!*s || read(fd, *s, BUFFER_SIZE) == -1)
		return (0);
	while (ft_len(*s, size) == -1)
	{
		size += BUFFER_SIZE;
		tmp = calloc(BUFFER_SIZE + 1, 1);
		if (!tmp || read(fd, *s, size) == -1)
			return (0);
		*s = ft_strjoin(*s, tmp);
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

static char	*get_line(char **s, int *i)
{
	int		size;
	char	*line;

	size = ft_size(*s + *i);
	if (size < 0)
	{
		line = malloc(size * -1 + 1);
		if (!line)
			return (0);
		ft_strlcpy(line, *s + *i, size * -1 + 1);
		free(*s);
		*i = -1;
	}
	else
	{
		line = malloc(size + 2);
		if (!line)
			return (0);
		ft_strlcpy(line, *s + *i, size + 2);
		*i = *i + (size + 1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	static int	i;

	if (i == -1)
		return (0);
	if (!s)
	{
		if (!ft_read(&s, fd))
			return (0);
	}
	return (get_line(&s, &i));
}
