/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:26:14 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/08 11:44:52 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void) x;
	(void) y;
	if (button == 4)
	{
		vars->zoom /= 2.0;
		vars->min_re = -0.643204547876 - vars->zoom;
		vars->max_re = -0.643204547876 + vars->zoom;
		vars->min_im = 0.4928155937603 - vars->zoom;
		vars->max_im = vars->min_im
			+ (vars->max_re - vars->min_re) * HEIGHT / WIDTH;
		fractal(vars);
	}
	else if (button == 5 && vars->zoom < 4)
	{
		vars->zoom *= 2.0;
		vars->min_re = -0.643204547876 - vars->zoom;
		vars->max_re = -0.643204547876 + vars->zoom;
		vars->min_im = 0.4928155937603 - vars->zoom;
		vars->max_im = vars->min_im
			+ (vars->max_re - vars->min_re) * HEIGHT / WIDTH;
		fractal(vars);
	}
	return (0);
}

void	window(int julia, double re, double im)
{
	t_vars	vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	vars.zoom = 2;
	vars.min_re = -0.643204547876 - vars.zoom;
	vars.max_re = -0.643204547876 + vars.zoom;
	vars.min_im = 0.4928155937603 - vars.zoom;
	vars.max_im = vars.min_im + (vars.max_re - vars.min_re) * HEIGHT / WIDTH;
	vars.re_arg = re;
	vars.im_arg = im;
	vars.julia = julia;
	fractal(&vars);
	mlx_hook(vars.win_ptr, 2, (1L << 0), key_hook, &vars);
	mlx_hook(vars.win_ptr, 17, 0, hook, &vars);
	mlx_mouse_hook(vars.win_ptr, mouse_hook, &vars);
	mlx_loop(vars.mlx_ptr);
}

int	main(int argc, char **argv)
{
	double	c_re;
	double	c_im;

	if (argc == 2)
	{
		if (!ft_strcmp(ft_tolower(argv[1]), "mandelbrot"))
			window(0, 0, 0);
		if (!ft_strcmp(ft_tolower(argv[1]), "julia"))
			window(1, 0.28072598610057, 0.0087);
	}
	if (argc == 4)
	{
		if (!ft_strcmp(ft_tolower(argv[1]), "julia"))
		{
			c_re = num(argv[2]);
			c_im = num(argv[3]);
			if (c_re != -1 && c_im != -1)
				window(1, c_re, c_im);
		}
	}
	write(1, HELP, 155);
}
