#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 400
#define WIDTH 400
#define MAX_ITERATIONS 1500

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	double minRe;
	double maxRe;
	double minIm;
	double maxIm;
	double zoom;
}	t_vars;

void mandelbrot(t_vars *vars)
{
	double Re_factor = (vars->maxRe-vars->minRe)/(WIDTH-1);
	double Im_factor = (vars->maxIm-vars->minIm)/(HEIGHT-1);
	unsigned n;

	for(unsigned y=0; y<HEIGHT; ++y)
	{
		double c_im = vars->maxIm - y*Im_factor;
		for(unsigned x=0; x<WIDTH; ++x)
		{
			double c_re = vars->minRe + x*Re_factor;

			double Z_re = c_re, Z_im = c_im;
			int isInside = 1;
			for(n=0; n<MAX_ITERATIONS; ++n)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(!isInside)
			{
				int c = 30 + n % 225;
				mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, x, y, c * 1000000 + (c * 2 % 255) * 1000 + c * 3 % 255);
			}
			else
				mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, x, y, 0);
		}
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 43)
	{
		vars->zoom /= 2.0;
		vars->minRe = -0.643204547876 - vars->zoom;
		vars->maxRe = -0.643204547876 + vars->zoom;
		vars->minIm = 0.4928155937603 - vars->zoom; //(vars->zoom * WIDTH / HEIGHT) / 2;
		vars->maxIm = vars->minIm+(vars->maxRe-vars->minRe)*HEIGHT/WIDTH;
		mandelbrot(vars);
	}
	else if (keycode == 45)
	{
		vars->zoom *= 2.0;
		vars->minRe = -0.643204547876 - vars->zoom;
		vars->maxRe = -0.643204547876 + vars->zoom;
		vars->minIm = 0.4928155937603 - vars->zoom;
		vars->maxIm = vars->minIm+(vars->maxRe-vars->minRe)*HEIGHT/WIDTH;
		mandelbrot(vars);
	}
	return (0);
}

int main()
{
	t_vars vars;
	
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "prova");
	vars.zoom = 2;
	vars.minRe = -0.643204547876 - vars.zoom;
	vars.maxRe = -0.643204547876 + vars.zoom;
	vars.minIm = 0.4928155937603 - vars.zoom;
	vars.maxIm = vars.minIm+(vars.maxRe-vars.minRe)*HEIGHT/WIDTH;
	mandelbrot(&vars);
	mlx_hook(vars.win_ptr, 2, (1L<<0), key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
}

