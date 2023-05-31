/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:32:55 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:33:52 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *file_name, t_vars *vars)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		write(2, file_name, ft_strlen(file_name));
		write(2, ": ", 2);
		perror("");
		free_map(vars);
		exit(1);
	}
	return (fd);
}

void	ext_check(char *file_name, char *ext, t_vars *vars)
{
	int		j;

	j = ft_strlen(file_name);
	if (j < 5 || file_name[j - 1] != ext[3] || file_name[j - 2]
		!= ext[2] || file_name[j - 3] != ext[1] || file_name[j - 4]
		!= ext[0])
	{
		write(2, "Error\n", 6);
		write(2, file_name, j);
		write(2, ": Invalid file extension\n", 26);
		free_map(vars);
		exit(1);
	}
}

void	tex_ext_check(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		ext_check(vars->map.tex[i], ".xpm", vars);
		close(open_file(vars->map.tex[i], vars));
	}
}

void	is_sprite_found(t_vars *vars, int x, int y, int *sprite_found)
{
	int	i;

	i = -1;
	if (*sprite_found)
		map_error(vars, 0, 0, "Invalid sprite number\n");
	while (++i < NUM_SPRITES)
	{
		vars->sprite[i].x = x + 0.5;
		vars->sprite[i].y = y + 0.5;
		vars->sprite[i].texture = 2;
	}
	*sprite_found = 1;
}

void	check_sprite_map(t_vars *vars)
{
	int	i;
	int	j;
	int	sprite_found;

	i = -1;
	sprite_found = 0;
	while (vars->map.map[++i])
	{
		j = -1;
		while (vars->map.map[i][++j] != '\n')
		{
			if (vars->map.map[i][j] == '2')
				is_sprite_found(vars, i, j, &sprite_found);
		}
	}
}
