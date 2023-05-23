/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_and_pixels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:15:19 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/19 10:16:33 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image(t_vars *vars)
{
	vars->images[0].img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->images[0].addr = mlx_get_data_addr(vars->images[0].img,
			&vars->images[0].bits_per_pixel,
			&vars->images[0].line_length,
			&vars->images[0].endian);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->images[0].addr + (y * vars->images[0].line_length
			+ x * (vars->images[0].bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel(t_vars *vars, int x, int y, int i)
{
	char	*dst;

	dst = vars->images[i].addr + (y * vars->images[i].line_length
			+ x * (vars->images[i].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
