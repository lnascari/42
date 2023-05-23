/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:13:42 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/23 14:19:04 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_split(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	free_map(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (vars->map.tex[i])
			free(vars->map.tex[i]);
	}
	if (vars->map.map)
		ft_free_split(vars->map.map);
}

void	map_error(t_vars *vars, char **split, char *line, int fd)
{
	free_map(vars);
	if (split)
		ft_free_split(split);
	if (line)
		free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int		check_set(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!vars->map.tex[i])
			return (0);
	}
	if (!vars->map.c_color[0] || !vars->map.f_color[0])
		return (0);
	return (1);
}

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

char	*ft_strcpy(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	check_id(t_vars *vars, char **split)
{
	if (!ft_strcmp(split[0], "NO") && !vars->map.tex[0])
	{
		vars->map.tex[0] = ft_calloc(ft_strlen(split[1]), 1);
		ft_strlcpy(vars->map.tex[0], split[1], ft_strlen(split[1]));
		return (1);
	}
	else if (!ft_strcmp(split[0], "WE") && !vars->map.tex[1])
	{
		vars->map.tex[1] = ft_calloc(ft_strlen(split[1]), 1);
		ft_strlcpy(vars->map.tex[1], split[1], ft_strlen(split[1]));
		return (1);
	}
	else if (!ft_strcmp(split[0], "SO") && !vars->map.tex[2])
	{
		vars->map.tex[2] = ft_calloc(ft_strlen(split[1]), 1);
		ft_strlcpy(vars->map.tex[2], split[1], ft_strlen(split[1]));
		return (1);
	}
	else if (!ft_strcmp(split[0], "EA") && !vars->map.tex[3])
	{
		vars->map.tex[3] = ft_calloc(ft_strlen(split[1]), 1);
		ft_strlcpy(vars->map.tex[3], split[1], ft_strlen(split[1]));
		return (1);
	}
	else if (!ft_strcmp(split[0], "F") && !vars->map.f_color[0])
		return (2);
	else if (!ft_strcmp(split[0], "C") && !vars->map.c_color[0])
		return (3);
	return (0);
}

void	check_line(t_vars *vars, char **split, char *line, int fd)
{
	char	**color;
	int		i;
	int		set;
	int		comma;

	i = -1;
	while (split[++i])
		;
	if (i != 2)
		map_error(vars, split, line, fd);
	set = check_id(vars, split);
	if (!set)
		map_error(vars, split, line, fd);
	if (set == 2 || set == 3)
	{
		comma = 0;
		i = -1;
		while (split[1][++i] && split[1][i] != '\n')
		{
			if (split[1][i] == ',')
				comma++;
			else if (split[1][i] < '0' || split[1][i] > '9')
				map_error(vars, split, line, fd);
		}
		if (comma != 2)
			map_error(vars, split, line, fd);
		color = ft_split(split[1], ',');
		i = -1;
		while (color[++i])
			;
		if (i != 3)
		{
			ft_free_split(color);
			map_error(vars, split, line, fd);
		}
		if (set == 2)
		{
			vars->map.f_color[0] = 1;
			vars->map.f_color[1] = ft_atoi(color[0]) * pow(2, 16)
				+ ft_atoi(color[1]) * pow(2, 8) + ft_atoi(color[2]);
		}
		else if (set == 3)
		{
			vars->map.c_color[0] = 1;
			vars->map.c_color[1] = ft_atoi(color[0]) * pow(2, 16)
				+ ft_atoi(color[1]) * pow(2, 8) + ft_atoi(color[2]);
		}
		ft_free_split(color);
	}
	ft_free_split(split);
}

void	check_map_line(t_vars *vars, char *line, int fd)
{
	int	i;

	i = -1;
	while(line[++i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			map_error(vars, 0, line, fd);
	}
}

void	ft_map(t_vars *vars, char *map)
{
	int		fd;
	int		count;
	int		size[2];
	char	*line;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(1);
	}
	count = 0;
	line = get_next_line(fd);
	while (line && !check_set(vars))
	{
		if (line[0] != '\n')
			check_line(vars, ft_split(line, ' '), line, fd);
		free(line);
		line = get_next_line(fd);
		count++;
	}
	ft_bzero(size, sizeof(int) * 2);
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
				map_error(vars, 0, line, fd);
			check_map_line(vars, line, fd);
			
		}
		free(line);
		line = get_next_line(fd);
		count++;
	}
	if (!size[0])
		map_error(vars, 0, 0, fd);
	if (!size[1])
		size[1] = count;
	vars->map.map = ft_calloc(size[1] - size[0] + 1, sizeof(char *));
	close(fd);
	fd = open(map, O_RDONLY);
	count = 0;
	while (count < size[0])
	{
		line = get_next_line(fd);
		free(line);
		count++;
	}
	i = -1;
	while (count < size[1])
	{
		line = get_next_line(fd);
		vars->map.map[++i] = line;
		count ++;
	}
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
}