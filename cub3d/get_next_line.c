/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:34:37 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/22 12:45:37 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*buff_join(char *buffer, char *tmp)
{
	char	*n_buffer;

	n_buffer = ft_strjoin(buffer, tmp);
	free(buffer);
	return (n_buffer);
}

char	*ft_read(char *buffer, int fd)
{
	char	*tmp;
	int		i;

	if (buffer == 0)
		buffer = ft_calloc(1, 1);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = 1;
	while (i > 0)
	{
		if (ft_strchr(buffer, '\n') == 0)
		{
			i = read(fd, tmp, BUFFER_SIZE);
			if (i < 0)
			{
				free(tmp);
				return (0);
			}
			tmp[i] = '\0';
			buffer = buff_join(buffer, tmp);
		}
		else
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*ft_new_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (0);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i ++;
	if (buffer[i] == '\n')
		i ++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i ++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_remove_line(char *buffer)
{
	char	*n_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i ++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (0);
	}
	i ++;
	j = i;
	while (buffer[j] != '\0')
		j ++;
	n_buffer = (char *)malloc((j - i + 1) * sizeof(char));
	j = 0;
	while (buffer[i] != '\0')
		n_buffer[j ++] = buffer[i ++];
	n_buffer[j] = '\0';
	free(buffer);
	return (n_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = ft_read(buffer, fd);
	line = ft_new_line(buffer);
	buffer = ft_remove_line(buffer);
	return (line);
}

/* int main()
{
	int		fd;
	char	*l;

	fd = open("sas.txt", O_RDONLY);
	l = get_next_line(fd);
	while (l != 0)
	{
		printf("%s", l);
		l = get_next_line(fd);
	}
	printf("\n");
} */
