/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:47:13 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:09:51 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assing_sprite_tex(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < NUM_SPRITES)
	{
		vars->sprite[i].image.img = mlx_xpm_file_to_image(vars->mlx,
				vars->sprite[i].file_name, &vars->sprite[i].w,
				&vars->sprite[i].h);
		vars->sprite[i].image.addr = mlx_get_data_addr(
				vars->sprite[i].image.img,
				&vars->sprite[i].image.bits_per_pixel,
				&vars->sprite[i].image.line_length,
				&vars->sprite[i].image.endian);
	}
}

void	sprite_init(t_vars *vars)
{
	vars->sprite[0].file_name = "./sprites/gengarframe00.xpm";
	vars->sprite[1].file_name = "./sprites/gengarframe01.xpm";
	vars->sprite[2].file_name = "./sprites/gengarframe02.xpm";
	vars->sprite[3].file_name = "./sprites/gengarframe03.xpm";
	vars->sprite[4].file_name = "./sprites/gengarframe04.xpm";
	vars->sprite[5].file_name = "./sprites/gengarframe05.xpm";
	vars->sprite[6].file_name = "./sprites/gengarframe06.xpm";
	vars->sprite[7].file_name = "./sprites/gengarframe07.xpm";
	vars->sprite[8].file_name = "./sprites/gengarframe08.xpm";
	vars->sprite[9].file_name = "./sprites/gengarframe09.xpm";
	vars->sprite[10].file_name = "./sprites/gengarframe10.xpm";
	vars->sprite[11].file_name = "./sprites/gengarframe11.xpm";
	vars->sprite[12].file_name = "./sprites/gengarframe12.xpm";
	vars->sprite[13].file_name = "./sprites/gengarframe13.xpm";
	assing_sprite_tex(vars);
}

void	draw_sprite(t_vars *vars, int d, int y)
{
	while (++vars->stripe < vars->draw_end_x)
	{
		vars->tex_x = (int)(256 * (vars->stripe - (-vars->sprite_width
						/ 2 + vars->sprite_screen_x))
				* vars->sprite[vars->sprite_count].w
				/ vars->sprite_width) / 256;
		if (vars->transform_y > 0 && vars->stripe > 0 && vars->stripe < WIDTH
			&& vars->transform_y < vars->z_buffer[vars->stripe])
		{
			y = vars->draw_start_y - 1;
			while (++y < vars->draw_end_y)
			{
				d = (y - vars->v_move_screen) * 256 - HEIGHT * 128
					+ vars->sprite_height * 128;
				vars->tex_y = ((d * vars->sprite[vars->sprite_count].h)
						/ vars->sprite_height) / 256;
				if ((unsigned)my_mlx_pixel_sprite(vars, vars->tex_x,
						vars->tex_y, vars->sprite_count) != 0xFF000000)
					my_mlx_pixel_put(vars, vars->stripe, y, my_mlx_pixel_sprite(
							vars, vars->tex_x, vars->tex_y, vars->sprite_count))
					;
			}
		}
	}
}

void	sprite_vars_init(t_vars *vars)
{
	vars->v_move_screen = (int)(-300.0 / vars->transform_y);
	vars->sprite_height = abs((int)(HEIGHT / (vars->transform_y))) * 2.0;
	vars->draw_start_y = -vars->sprite_height / 2 + HEIGHT / 2
		+ vars->v_move_screen;
	if (vars->draw_start_y < 0)
		vars->draw_start_y = 0;
	vars->draw_end_y = vars->sprite_height / 2 + HEIGHT / 2
		+ vars->v_move_screen;
	if (vars->draw_end_y >= HEIGHT)
		vars->draw_end_y = HEIGHT - 1;
	vars->sprite_width = abs((int)(HEIGHT / (vars->transform_y))) * 2.0;
	vars->draw_start_x = -vars->sprite_width / 2 + vars->sprite_screen_x;
	if (vars->draw_start_x < 0)
		vars->draw_start_x = 0;
	vars->draw_end_x = vars->sprite_width / 2 + vars->sprite_screen_x;
	if (vars->draw_end_x >= WIDTH)
		vars->draw_end_x = WIDTH - 1;
	vars->stripe = vars->draw_start_x - 1;
}

void	put_sprite(t_vars *vars)
{
	vars->sprite_x = vars->sprite[vars->sprite_count].x - vars->pos_x;
	vars->sprite_y = vars->sprite[vars->sprite_count].y - vars->pos_y;
	vars->inv_det = 1.0 / (vars->plane_x * vars->dir_y - vars->dir_x
			* vars->plane_y);
	vars->transform_x = vars->inv_det * (vars->dir_y * vars->sprite_x
			- vars->dir_x * vars->sprite_y);
	vars->transform_y = vars->inv_det * (-vars->plane_y * vars->sprite_x
			+ vars->plane_x * vars->sprite_y);
	vars->sprite_screen_x = (int)((WIDTH / 2) * (1 + vars->transform_x
				/ vars->transform_y));
	sprite_vars_init(vars);
	draw_sprite(vars, 0, 0);
	if (vars->sprite_i_count ++ == 20)
	{
		vars->sprite_count ++;
		vars->sprite_i_count = 0;
	}
}
