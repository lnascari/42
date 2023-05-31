/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:08:13 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:45:31 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define NUM_SPRITES 14
# define WIDTH 1000
# define HEIGHT 800
# define ESC_KEY 65307
# define ARR_LEFT 65361
# define ARR_RIGHT 65363
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100

# define BUFFER_SIZE 256

# define M_PI 3.14159265358979323846

typedef struct s_map
{
	char	*tex[4];
	int		w[4];
	int		h[4];
	int		f_color[2];
	int		c_color[2];
	char	**map;
}	t_map;

typedef struct s_img_vars
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_vars;

typedef struct s_prite
{
	int			w;
	int			h;
	t_img_vars	image;
	double		x;
	double		y;
	char		*file_name;
	int			texture;
}	t_sprite;

typedef struct s_vars
{
	t_map		map;
	t_sprite	sprite[NUM_SPRITES];
	int			fd;
	void		*mlx;
	void		*win;
	t_img_vars	images[5];
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		old_dir_x;
	double		old_plane_x;
	char		spawn_char;
	double		wall_x;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
	int			w_is_pressed;
	int			a_is_pressed;
	int			s_is_pressed;
	int			d_is_pressed;
	int			p_is_rotating_r;
	int			p_is_rotating_l;
	double		z_buffer[WIDTH];
	double		sprite_dist[NUM_SPRITES];
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			stripe;
	int			v_move_screen;
	int			sprite_count;
	int			sprite_i_count;
}	t_vars;

int				x_hook(t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int				key_release_hook(int keycode, t_vars *vars);
void			arr_left(t_vars *vars);
void			arr_right(t_vars *vars);

int				open_file(char *file_name, t_vars *vars);
void			ground_and_sky(t_vars *vars);
void			ray_casting_loop(t_vars *vars);
void			ext_check(char *file_name, char *ext, t_vars *vars);

void			w_key(t_vars *vars);
void			a_key(t_vars *vars);
void			s_key(t_vars *vars);
void			d_key(t_vars *vars);

void			side_hit(t_vars *vars);
void			line_ops(t_vars *vars);
void			tex_ops(t_vars *vars);
void			dir_and_dist(t_vars *vars);
void			inits(t_vars *vars);

void			image(t_vars *vars);
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
unsigned int	my_mlx_pixel(t_vars *vars, int x, int y, int i);
unsigned int	my_mlx_pixel_sprite(t_vars *vars, int x, int y, int i);

void			player_pos(t_vars *vars);
void			check_start_dir_ns(t_vars *vars);
void			check_start_dir_ew(t_vars *vars);

char			*get_next_line(int fd);

void			ft_map(t_vars *vars, char *map);
void			check_map_format(t_vars *vars);
char			*ft_strcpy_trim(char *src);
int				ft_strcmp(char *s1, char *s2);

void			sprite_init(t_vars *vars);
void			put_sprite(t_vars *vars);

void			exit_and_destroy(t_vars *vars);
void			free_map(t_vars *vars);
void			map_error(t_vars *vars, char **split, char *line, char *error);
void			ft_free_split(char **s);

void			tex_ext_check(t_vars *vars);
void			check_sprite_map(t_vars *vars);

void			check_line(t_vars *vars, char **split, char *line);
void			check_map_line(t_vars *vars, char *line);

int				check_set(t_vars *vars);
int				check_id(t_vars *vars, char **split);

#endif