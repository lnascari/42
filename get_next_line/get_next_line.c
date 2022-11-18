/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:20:37 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/18 15:36:11 by lnascari         ###   ########.fr       */
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
		if (i == size)
			return (-1);
		i++;
	}
	return (i);
}

static void	ft_read(char **s, int fd)
{
	int	size;

	size = BUFFER_SIZE;
	*s = malloc(size + 1);
	if (read(fd, s, size) == -1)
		return (0);
	while (ft_len(s, size) == -1)
	{
		free(*s);
		size += BUFFER_SIZE;
		*s = malloc(size + 1);
		if (read(fd, *s, size) == -1)
			return (0);
	}
	*s[size] = 0;
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
	if (size < 0)
	{
		line = malloc(size * -1 + 1);
		ft_strlcpy(line, *s, size * -1 + 1);
		free(*s);
		*s = malloc(1);
		s[0] = 0;
	}
	else
	{
		line = malloc(size + 2);
		ft_strlcpy(line, *s, size + 2);
		*s = *s + (size + 1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;

	if (!s)
		ft_read(&s, fd);
	if (s[0] == 0 || (!s))
		return (0);
	return (get_line(&s));
}