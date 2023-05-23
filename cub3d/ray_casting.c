/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:47:26 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/23 14:14:32 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	side_hit(t_vars *vars)
{
	while (vars->hit == 0)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_dist_x;
			vars->map_x += vars->step_x;
			vars->side = 0;
		}
		else
		{
			vars->side_dist_y += vars->delta_dist_y;
			vars->map_y += vars->step_y;
			vars->side = 1;
		}
		if (vars->map.map[vars->map_x][vars->map_y] == '1')
			vars->hit = 1;
		if (vars->hit && vars->side == 0 && vars->pos_x >= vars->map_x)
			vars->side = 2;
		else if (vars->hit && vars->side == 1 && vars->pos_y >= vars->map_y)
			vars->side = 3;
	}
}

void	line_ops(t_vars *vars)
{
	if (vars->side == 0 || vars->side == 2)
		vars->perp_wall_dist = (vars->side_dist_x - vars->delta_dist_x);
	else
		vars->perp_wall_dist = (vars->side_dist_y - vars->delta_dist_y);
	vars->line_height = (int)(HEIGHT / vars->perp_wall_dist);
	vars->draw_start = -vars->line_height / 2 + HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + HEIGHT / 2;
	if (vars->draw_end >= HEIGHT)
		vars->draw_end = HEIGHT - 1;
	if (vars->side == 0 || vars->side == 2)
		vars->wall_x = vars->pos_y + vars->perp_wall_dist * vars->ray_dir_y;
	else
		vars->wall_x = vars->pos_x + vars->perp_wall_dist * vars->ray_dir_x;
}

void	tex_ops(t_vars *vars)
{
	vars->wall_x -= floor(vars->wall_x);
	vars->tex_x = (int)(vars->wall_x * (double) vars->map.w[vars->side]);
	if ((vars->side == 0 || vars->side == 2) && vars->ray_dir_x > 0)
		vars->tex_x = vars->map.w[vars->side] - vars->tex_x - 1;
	if ((vars->side == 1 || vars->side == 3) && vars->ray_dir_y < 0)
		vars->tex_x = vars->map.w[vars->side] - vars->tex_x - 1;
	vars->step = 1.0 * vars->map.h[vars->side] / vars->line_height;
	vars->tex_pos = (vars->draw_start - HEIGHT
			/ 2 + vars->line_height / 2) * vars->step;
}

void	dir_and_dist(t_vars *vars)
{
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (vars->pos_x - vars->map_x)
			* vars->delta_dist_x;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->map_x + 1.0 - vars->pos_x)
			* vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (vars->pos_y - vars->map_y)
			* vars->delta_dist_y;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->map_y + 1.0 - vars->pos_y)
			* vars->delta_dist_y;
	}
}

void	inits(t_vars *vars)
{
	vars->hit = 0;
	vars->ray_dir_x = vars->dir_x + vars->plane_x * vars->camera_x;
	vars->ray_dir_y = vars->dir_y + vars->plane_y * vars->camera_x;
	vars->map_x = (int)vars->pos_x;
	vars->map_y = (int)vars->pos_y;
	if (vars->ray_dir_x == 0)
		vars->delta_dist_x = pow(10, 30);
	else
		vars->delta_dist_x = fabs(1 / vars->ray_dir_x);
	if (vars->ray_dir_y == 0)
		vars->delta_dist_y = pow(10, 30);
	else
		vars->delta_dist_y = fabs(1 / vars->ray_dir_y);
}
