/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:13:42 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:43:30 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0 && s2[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strcpy_trim(char *src)
{
	char	*dest;

	dest = ft_calloc(ft_strlen(src), 1);
	ft_strlcpy(dest, src, ft_strlen(src));
	return (dest);
}

void	assign_map(t_vars *vars, int size[], char *map)
{
	char	*line;
	int		count;
	int		i;

	vars->fd = open(map, O_RDONLY);
	count = 0;
	while (count < size[0])
	{
		line = get_next_line(vars->fd);
		free(line);
		count++;
	}
	i = -1;
	while (count < size[1])
	{
		line = get_next_line(vars->fd);
		vars->map.map[++i] = line;
		count ++;
	}
	while (line)
	{
		line = get_next_line(vars->fd);
		free(line);
	}
	close(vars->fd);
}

void	map_size(t_vars *vars, int size[], int count, char *line)
{
	while (line)
	{
		if (line[0] == '\n')
		{
			if (size[0] && !size[1])
				size[1] = count;
		}
		else
		{
			if (!size[0])
				size[0] = count;
			else if (size[0] && size[1])
				map_error(vars, 0, line, "Invalid map line\n");
			check_map_line(vars, line);
		}
		free(line);
		line = get_next_line(vars->fd);
		count++;
	}
	if (!size[0])
		map_error(vars, 0, 0, "No map detected\n");
	if (!size[1])
		size[1] = count;
}

void	ft_map(t_vars *vars, char *map)
{
	int		count;
	int		size[2];
	char	*line;

	ext_check(map, ".cub", vars);
	vars->fd = open_file(map, vars);
	count = 0;
	line = get_next_line(vars->fd);
	while (line && !check_set(vars))
	{
		if (line[0] != '\n')
			check_line(vars, ft_split(line, ' '), line);
		free(line);
		line = get_next_line(vars->fd);
		count++;
	}
	ft_bzero(size, sizeof(int) * 2);
	map_size(vars, size, count, line);
	vars->map.map = ft_calloc(size[1] - size[0] + 1, sizeof(char *));
	close(vars->fd);
	assign_map(vars, size, map);
}
