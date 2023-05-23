/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:11:03 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/23 13:34:20 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_hook(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(vars->mlx, vars->images[i].img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars);
	exit(0);
	return (0);
}

void	arr_left(t_vars *vars)
{
	vars->old_dir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(0.174533) - vars->dir_y * sin(0.174533);
	vars->dir_y = vars->old_dir_x * sin(0.174533)
		+ vars->dir_y * cos(0.174533);
	vars->old_plane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(0.174533)
		- vars->plane_y * sin(0.174533);
	vars->plane_y = vars->old_plane_x * sin(0.174533)
		+ vars->plane_y * cos(0.174533);
	mlx_destroy_image(vars->mlx, vars->images[0].img);
	ground_and_sky(vars);
	ray_casting_loop(vars);
}

void	arr_right(t_vars *vars)
{
	vars->old_dir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(-0.174533)
		- vars->dir_y * sin(-0.174533);
	vars->dir_y = vars->old_dir_x * sin(-0.174533)
		+ vars->dir_y * cos(-0.174533);
	vars->old_plane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(-0.174533)
		- vars->plane_y * sin(-0.174533);
	vars->plane_y = vars->old_plane_x * sin(-0.174533)
		+ vars->plane_y * cos(-0.174533);
	mlx_destroy_image(vars->mlx, vars->images[0].img);
	ground_and_sky(vars);
	ray_casting_loop(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	i;

	if (keycode == ESC_KEY)
	{
		i = -1;
		while (++i < 5)
			mlx_destroy_image(vars->mlx, vars->images[i].img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free_map(vars);
		exit(0);
	}
	else if (keycode == W_KEY)
		w_key(vars);
	else if (keycode == A_KEY)
		a_key(vars);
	else if (keycode == S_KEY)
		s_key(vars);
	else if (keycode == D_KEY)
		d_key(vars);
	else if (keycode == ARR_LEFT)
		arr_left(vars);
	else if (keycode == ARR_RIGHT)
		arr_right(vars);
	return (0);
}
