/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:26:14 by lnascari          #+#    #+#             */
/*   Updated: 2022/12/19 16:04:23 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 65307)
		exit(0);
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
	mlx_mouse_hook(vars.win_ptr, mouse_hook, &vars);
	mlx_loop(vars.mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1][0] == 'm')
		{
			window(0, 0, 0);
		}
		if (argv[1][0] == 'j')
		{
			window(1, 0.277916, 0.01);
		}
	}
	
}
