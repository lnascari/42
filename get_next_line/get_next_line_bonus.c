/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:31:03 by lnascari          #+#    #+#             */
/*   Updated: 2023/10/22 12:31:04 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char *str, int fd)
{
	char	*tmp;
	int		size;

	size = BUFFER_SIZE;
	if (!str)
		str = ft_calloc(1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (size == BUFFER_SIZE && !ft_strchr(str, '\n'))
	{
		size = read(fd, tmp, BUFFER_SIZE);
		tmp[size] = 0;
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

size_t	line_len(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i + 1);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*line;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	str[fd] = read_line(str[fd], fd);
	if (!str[fd] || !str[fd][0])
	{
		free(str[fd]);
		str[fd] = 0;
		return (0);
	}
	line = ft_substr(str[fd], 0, line_len(str[fd]));
	tmp = ft_strchr(str[fd], '\n');
	if (tmp)
		tmp = ft_substr(str[fd], line_len(str[fd]), ft_strlen(tmp + 1));
	free(str[fd]);
	str[fd] = tmp;
	return (line);
}
