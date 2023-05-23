/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:08:10 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/23 13:54:20 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ground_and_sky(t_vars *vars)
{
	int	x;
	int	y;

	image(vars);
	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y < HEIGHT / 2)
			my_mlx_pixel_put(vars, x, y, vars->map.c_color[1]);
		while (y <= HEIGHT)
		{
			my_mlx_pixel_put(vars, x, y, vars->map.f_color[1]);
			y ++;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images[0].img, 0, 0);
}

void	ray_casting_loop(t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		vars->camera_x = 2 * x / (double)WIDTH - 1;
		inits(vars);
		dir_and_dist(vars);
		side_hit(vars);
		line_ops(vars);
		tex_ops(vars);
		y = vars->draw_start - 1;
		while (++y < vars->draw_end)
		{
			vars->tex_y = (int)vars->tex_pos & (vars->map.h[vars->side] - 1);
			vars->tex_pos += vars->step;
			if ((unsigned)my_mlx_pixel(vars, vars->tex_x,
					vars->tex_y, vars->side + 1) != 0xFF000000)
				my_mlx_pixel_put(vars, x, y, my_mlx_pixel(vars, vars->tex_x,
						vars->tex_y, vars->side + 1));
		}
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->images[0].img, 0, 0);
	}
}

void	assign_textures(t_vars	*vars)
{
	int		i;

	i = 0;
	while (++i < 5)
	{
		vars->images[i].img = mlx_xpm_file_to_image(vars->mlx,
				vars->map.tex[i - 1], &vars->map.w[i - 1], &vars->map.h[i - 1]);
		vars->images[i].addr = mlx_get_data_addr(vars->images[i].img,
				&vars->images[i].bits_per_pixel,
				&vars->images[i].line_length, &vars->images[i].endian);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	ft_bzero(&vars, sizeof(t_vars));
	ft_map(&vars, argv[1]);
	player_pos(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "cub3D");
	mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
	mlx_hook(vars.win, 17, 0, x_hook, &vars);
	assign_textures(&vars);
	ground_and_sky(&vars);
	if (vars.spawn_char == 'N' || vars.spawn_char == 'S')
		check_start_dir_ns(&vars);
	else if (vars.spawn_char == 'E' || vars.spawn_char == 'W')
		check_start_dir_ew(&vars);
	ray_casting_loop(&vars);
	mlx_loop(vars.mlx);
}
