/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:43:50 by lnascari          #+#    #+#             */
/*   Updated: 2022/12/19 15:34:50 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# define FRACTOL_H
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITERATIONS 730
# define HELP "Usage:\n\n  fractol mandelbrot\n\n  fractol julia [C_RE] [C_IM]\n\
	\n    double C_RE (-1 >= && 1 =<)  default: 0.28072598610057\
	\n    double C_IM (-1 >= && 1 <=)  default: 0.0087\n"

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	zoom;
	double	re_factor;
	double	im_factor;
	double	re_arg;
	double	im_arg;
	int		julia;
}	t_vars;

void	fractal(t_vars *vars);

#endif