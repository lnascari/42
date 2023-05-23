/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:17:40 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/23 11:05:26 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_spawn_set(int spawn_set)
{
	if (!spawn_set)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
}

void	set_spawn(t_vars *vars, int *spawn_set, int x, int y)
{
	vars->pos_x = x + 0.5;
	vars->pos_y = y + 0.5;
	vars->spawn_char = vars->map.map[x][y];
	*spawn_set = 1;
}

void	player_pos(t_vars *vars)
{
	int	x;
	int	y;
	int	spawn_set;

	spawn_set = 0;
	x = -1;
	while (vars->map.map[++x])
	{
		y = -1;
		while (vars->map.map[x][++y])
		{
			if (spawn_set && (vars->map.map[x][y] == 'N'
				|| vars->map.map[x][y] == 'S' || vars->map.map[x][y] == 'E'
				|| vars->map.map[x][y] == 'W'))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			if (vars->map.map[x][y] == 'N' || vars->map.map[x][y] == 'S'
					|| vars->map.map[x][y] == 'E' || vars->map.map[x][y] == 'W')
				set_spawn(vars, &spawn_set, x, y);
		}
	}
	check_spawn_set(spawn_set);
}

void	check_start_dir_ns(t_vars *vars)
{
	if (vars->spawn_char == 'N')
	{
		vars->dir_x = -1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = 0.66;
	}
	else if (vars->spawn_char == 'S')
	{
		vars->dir_x = 1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = -0.66;
	}
}

void	check_start_dir_ew(t_vars *vars)
{
	if (vars->spawn_char == 'E')
	{
		vars->dir_x = 0;
		vars->dir_y = 1;
		vars->plane_x = 0.66;
		vars->plane_y = 0;
	}
	else if (vars->spawn_char == 'W')
	{
		vars->dir_x = 0;
		vars->dir_y = -1;
		vars->plane_x = -0.66;
		vars->plane_y = 0;
	}
}
