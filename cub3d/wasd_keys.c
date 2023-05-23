/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:38:17 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/23 10:55:19 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(t_vars *vars)
{
	if (vars->map.map[(int)(vars->pos_x
			+ vars->dir_x * 0.2)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		+ vars->dir_x * 0.2)][(int)vars->pos_y] == vars->spawn_char)
		vars->pos_x += vars->dir_x * 0.2;
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_y * 0.2)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_y * 0.2)] == vars->spawn_char)
		vars->pos_y += vars->dir_y * 0.2;
	mlx_destroy_image(vars->mlx, vars->images[0].img);
	ground_and_sky(vars);
	ray_casting_loop(vars);
}

void	a_key(t_vars *vars)
{
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_x * 0.2)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		+ vars->dir_x * 0.2)] == vars->spawn_char)
		vars->pos_y += vars->dir_x * 0.2;
	if (vars->map.map[(int)(vars->pos_x
			- vars->dir_y * 0.2)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		- vars->dir_y * 0.2)][(int)vars->pos_y] == vars->spawn_char)
		vars->pos_x -= vars->dir_y * 0.2;
	mlx_destroy_image(vars->mlx, vars->images[0].img);
	ground_and_sky(vars);
	ray_casting_loop(vars);
}

void	s_key(t_vars *vars)
{
	if (vars->map.map[(int)(vars->pos_x
			- vars->dir_x * 0.2)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		- vars->dir_x * 0.2)][(int)vars->pos_y] == vars->spawn_char)
		vars->pos_x -= vars->dir_x * 0.2;
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_y * 0.2)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_y * 0.2)] == vars->spawn_char)
		vars->pos_y -= vars->dir_y * 0.2;
	mlx_destroy_image(vars->mlx, vars->images[0].img);
	ground_and_sky(vars);
	ray_casting_loop(vars);
}

void	d_key(t_vars *vars)
{
	if (vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_x * 0.2)] == '0'
		|| vars->map.map[(int)vars->pos_x][(int)(vars->pos_y
		- vars->dir_x * 0.2)] == vars->spawn_char)
		vars->pos_y -= vars->dir_x * 0.2;
	if (vars->map.map[(int)(vars->pos_x
			+ vars->dir_y * 0.2)][(int)vars->pos_y] == '0'
		|| vars->map.map[(int)(vars->pos_x
		+ vars->dir_y * 0.2)][(int)vars->pos_y] == vars->spawn_char)
		vars->pos_x += vars->dir_y * 0.2;
	mlx_destroy_image(vars->mlx, vars->images[0].img);
	ground_and_sky(vars);
	ray_casting_loop(vars);
}
