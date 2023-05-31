/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:36:31 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:42:40 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_line(t_vars *vars, char *line)
{
	int	i;

	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != '2' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			map_error(vars, 0, line, "Invalid map character\n");
	}
}

int	is_char_valid(t_vars *vars, char c)
{
	if (c == '1' || c == '0' || c == vars->spawn_char || c == '2')
		return (1);
	return (0);
}

void	check_in_map_char(t_vars *vars, size_t i)
{
	size_t	j;

	j = -1;
	while (vars->map.map[i][++j] != '\n')
	{
		if (vars->map.map[i][j] == '0'
			|| vars->map.map[i][j] == vars->spawn_char
			|| vars->map.map[i][j] == '2')
		{
			if (ft_strlen(vars->map.map[i - 1]) > j
				&& ft_strlen(vars->map.map[i + 1]) > j)
			{
				if (!is_char_valid(vars, vars->map.map[i][j - 1])
					|| !is_char_valid(vars, vars->map.map[i][j + 1])
					|| !is_char_valid(vars, vars->map.map[i - 1][j])
					|| !is_char_valid(vars, vars->map.map[i + 1][j]))
					map_error(vars, 0, 0, "Invalid map format\n");
			}
			else
				map_error(vars, 0, 0, "Invalid map format\n");
		}
	}
}

void	check_map_format(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (vars->map.map[++i])
	{
		if (!i || !vars->map.map[i + 1])
		{
			j = -1;
			while (vars->map.map[i][++j] && vars->map.map[i][j] != '\n')
			{
				if (vars->map.map[i][j] != ' ' && vars->map.map[i][j] != '1')
					map_error(vars, 0, 0, "Invalid map format\n");
			}
		}
		else
			check_in_map_char(vars, i);
	}
}
