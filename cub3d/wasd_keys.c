/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:38:17 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/29 16:04:30 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(t_vars *vars)
{
	if (vars->map.map[(int)(vars->pos_x
			+ vars->dir_x * 0.033)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		+ vars->dir_x * 0.033)][(int)vars->pos_y] == vars->spawn_char
		|| vars->map.map[(int)(vars->pos_x
		+ vars->dir_x * 0.033)][(int)vars->pos_y] == '2')
		vars->pos_x += vars->dir_x * 0.033;
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_y * 0.033)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_y * 0.033)] == vars->spawn_char
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_y * 0.033)] == '2')
		vars->pos_y += vars->dir_y * 0.033;
}

void	a_key(t_vars *vars)
{
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_x * 0.033)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_x * 0.033)] == vars->spawn_char
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_x * 0.033)] == '2')
		vars->pos_y += vars->dir_x * 0.033;
	if (vars->map.map[(int)(vars->pos_x
			- vars->dir_y * 0.033)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		- vars->dir_y * 0.033)][(int)vars->pos_y] == vars->spawn_char
		|| vars->map.map[(int)(vars->pos_x
		- vars->dir_y * 0.033)][(int)vars->pos_y] == '2')
		vars->pos_x -= vars->dir_y * 0.033;
}

void	s_key(t_vars *vars)
{
	if (vars->map.map[(int)(vars->pos_x
			- vars->dir_x * 0.033)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		- vars->dir_x * 0.033)][(int)vars->pos_y] == vars->spawn_char
		|| vars->map.map[(int)(vars->pos_x
		- vars->dir_x * 0.033)][(int)vars->pos_y] == '2')
		vars->pos_x -= vars->dir_x * 0.033;
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_y * 0.033)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_y * 0.033)] == vars->spawn_char
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_y * 0.033)] == '2')
		vars->pos_y -= vars->dir_y * 0.033;
}

void	d_key(t_vars *vars)
{
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_x * 0.033)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_x * 0.033)] == vars->spawn_char
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_x * 0.033)] == '2')
		vars->pos_y -= vars->dir_x * 0.033;
	if (vars->map.map[(int)(vars->pos_x
			+ vars->dir_y * 0.033)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		+ vars->dir_y * 0.033)][(int)vars->pos_y] == vars->spawn_char
		|| vars->map.map[(int)(vars->pos_x
		+ vars->dir_y * 0.033)][(int)vars->pos_y] == '2')
		vars->pos_x += vars->dir_y * 0.033;
}
