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
# define FRACTOL_H
# define HEIGHT 800
# define WIDTH 800
# define MAX_ITERATIONS 1500
# include "./minilibx-linux/mlx.h"
# include <stdlib.h>

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
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