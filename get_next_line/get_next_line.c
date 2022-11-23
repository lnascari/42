/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:20:37 by lnascari          #+#    #+#             */
/*   Updated: 2022/11/23 12:57:59 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	ft_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (i == BUFFER_SIZE - 1)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_read(char **s, int fd)
{
	char	*tmp;
	int		b;

	b = ft_check(*s);
	while (b)
	{
		tmp = ft_calloc(BUFFER_SIZE, 1);
		if (!tmp || read(fd, tmp, BUFFER_SIZE) == -1)
			return (0);
		b = ft_check(tmp);
		if (!*s)
			*s = tmp;
		else
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

static char	*get_line(char **s)
{
	int		size;
	char	*line;
	char	*tmp;

	size = ft_size(*s);
	if (size <= 0)
	{
		line = ft_strlcpy(*s, size * -1 + 1, 1);
		if (!line)
			return (0);
		*s = ft_calloc(1, 1);
	}
	else
	{
		line = ft_strlcpy(*s, size + 2, 0);
		*s = ft_strlcpy(*s + (size + 1), ft_strlen(*s) - size, 1);
		if (!line || !*s)
			return (0);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	
	if ((s && s[0] == 0) || BUFFER_SIZE <= 0)
		return (0);
	if (!ft_read(&s, fd))
		return (0);
	return (get_line(&s));
}
