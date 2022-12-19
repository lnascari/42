/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:41 by lnascari          #+#    #+#             */
/*   Updated: 2022/12/19 15:34:40 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check(double z_re, double z_im, double c_re, double c_im)
{
	int		n;
	double	z_re2;
	double	z_im2;

	n = 0;
	while (++n <= MAX_ITERATIONS)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (n);
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
	}
	return (0);
}

void	color(int n, int x, int y, t_vars *vars)
{
	int	c;

	if (n)
	{
		c = 30 + (n - 1) % 225;
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, x, y,
			c * 1000000 + (c * 2 % 255) * 1000 + c * 3 % 255);
	}
	else
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, x, y, 0);
}

void	fractal(t_vars *vars)
{
	double	c_re;
	double	c_im;
	int		x;
	int		y;

	vars->re_factor = (vars->max_re - vars->min_re) / (WIDTH - 1);
	vars->im_factor = (vars->max_im - vars->min_im) / (HEIGHT - 1);
	y = -1;
	while (++y < HEIGHT)
	{
		c_im = vars->max_im - y * vars->im_factor;
		x = -1;
		while (++x < WIDTH)
		{
			c_re = vars->min_re + x * vars->re_factor;
			if (vars->julia)
				color(check(c_re, c_im, vars->re_arg, vars->im_arg), x, y, vars);
			else
				color(check(c_re, c_im, c_re, c_im), x, y, vars);
		}
	}
}
