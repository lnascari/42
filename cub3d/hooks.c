/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:11:03 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:07:28 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_hook(t_vars *vars)
{
	exit_and_destroy(vars);
	return (0);
}

void	arr_left(t_vars *vars)
{
	vars->old_dir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(M_PI / 300)
		- vars->dir_y * sin(M_PI / 300);
	vars->dir_y = vars->old_dir_x * sin(M_PI / 300)
		+ vars->dir_y * cos(M_PI / 300);
	vars->old_plane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(M_PI / 300)
		- vars->plane_y * sin(M_PI / 300);
	vars->plane_y = vars->old_plane_x * sin(M_PI / 300)
		+ vars->plane_y * cos(M_PI / 300);
}

void	arr_right(t_vars *vars)
{
	vars->old_dir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(-M_PI / 300)
		- vars->dir_y * sin(-M_PI / 300);
	vars->dir_y = vars->old_dir_x * sin(-M_PI / 300)
		+ vars->dir_y * cos(-M_PI / 300);
	vars->old_plane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(-M_PI / 300)
		- vars->plane_y * sin(-M_PI / 300);
	vars->plane_y = vars->old_plane_x * sin(-M_PI / 300)
		+ vars->plane_y * cos(-M_PI / 300);
}

int	key_release_hook(int keycode, t_vars *vars)
{
	if (keycode == W_KEY)
		vars->w_is_pressed = 0;
	if (keycode == A_KEY)
		vars->a_is_pressed = 0;
	if (keycode == S_KEY)
		vars->s_is_pressed = 0;
	if (keycode == D_KEY)
		vars->d_is_pressed = 0;
	if (keycode == ARR_LEFT)
		vars->p_is_rotating_l = 0;
	if (keycode == ARR_RIGHT)
		vars->p_is_rotating_r = 0;
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		exit_and_destroy(vars);
	else if (keycode == W_KEY)
		vars->w_is_pressed = 1;
	else if (keycode == A_KEY)
		vars->a_is_pressed = 1;
	else if (keycode == S_KEY)
		vars->s_is_pressed = 1;
	else if (keycode == D_KEY)
		vars->d_is_pressed = 1;
	else if (keycode == ARR_LEFT)
		vars->p_is_rotating_l = 1;
	else if (keycode == ARR_RIGHT)
		vars->p_is_rotating_r = 1;
	return (0);
}
