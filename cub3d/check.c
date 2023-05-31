/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:42:16 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:46:14 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_set(t_vars *vars)
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

int	check_id(t_vars *vars, char **split)
{
	if (!ft_strcmp(split[0], "NO") && !vars->map.tex[0])
	{
		vars->map.tex[0] = ft_strcpy_trim(split[1]);
		return (1);
	}
	else if (!ft_strcmp(split[0], "WE") && !vars->map.tex[1])
	{
		vars->map.tex[1] = ft_strcpy_trim(split[1]);
		return (1);
	}
	else if (!ft_strcmp(split[0], "SO") && !vars->map.tex[2])
	{
		vars->map.tex[2] = ft_strcpy_trim(split[1]);
		return (1);
	}
	else if (!ft_strcmp(split[0], "EA") && !vars->map.tex[3])
	{
		vars->map.tex[3] = ft_strcpy_trim(split[1]);
		return (1);
	}
	else if (!ft_strcmp(split[0], "F") && !vars->map.f_color[0])
		return (2);
	else if (!ft_strcmp(split[0], "C") && !vars->map.c_color[0])
		return (3);
	return (0);
}

char	**check_color(t_vars *vars, char **split, char *line, int i_et_c[2])
{
	char	**color;

	while (split[1][++i_et_c[0]] && split[1][i_et_c[0]] != '\n')
	{
		if (split[1][i_et_c[0]] == ',')
			i_et_c[1]++;
		else if (split[1][i_et_c[0]] < '0' || split[1][i_et_c[0]] > '9')
			map_error(vars, split, line, "Invalid RGB color format\n");
	}
	if (i_et_c[1] != 2)
		map_error(vars, split, line, "Invalid RGB color format\n");
	color = ft_split(split[1], ',');
	i_et_c[0] = -1;
	while (color[++i_et_c[0]])
		;
	if (ft_strlen(color[0]) > 3 || ft_atoi(color[0]) > 255
		|| ft_strlen(color[1]) > 3 || ft_atoi(color[1]) > 255
		|| ft_strlen(color[2]) > 4 || ft_atoi(color[2]) > 255
		|| i_et_c[0] != 3 || color[2][0] == '\n')
	{
		ft_free_split(color);
		map_error(vars, split, line, "Invalid RGB color format\n");
	}
	return (color);
}

void	assign_color(t_vars *vars, char **color, int set)
{
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
}

void	check_line(t_vars *vars, char **split, char *line)
{
	char	**color;
	int		i;
	int		set;
	int		i_et_c[2];

	i_et_c[0] = -1;
	i_et_c[1] = 0;
	i = -1;
	while (split[++i])
		;
	if (i != 2)
		map_error(vars, split, line, "Invalid map element format\n");
	set = check_id(vars, split);
	if (!set)
		map_error(vars, split, line, "Invalid id or redefinition\n");
	if (set == 2 || set == 3)
	{
		color = check_color(vars, split, line, i_et_c);
		assign_color(vars, color, set);
		ft_free_split(color);
	}
	ft_free_split(split);
}
