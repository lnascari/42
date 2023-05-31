/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:06:35 by gpaoline          #+#    #+#             */
/*   Updated: 2023/05/31 11:07:35 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_split(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	free_map(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (vars->map.tex[i])
			free(vars->map.tex[i]);
	}
	if (vars->map.map)
		ft_free_split(vars->map.map);
}

void	map_error(t_vars *vars, char **split, char *line, char *error)
{
	free_map(vars);
	if (split)
		ft_free_split(split);
	if (line)
		free(line);
	while (line)
	{
		line = get_next_line(vars->fd);
		free(line);
	}
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(1);
}

void	exit_and_destroy(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(vars->mlx, vars->images[i].img);
	i = -1;
	while (++i < NUM_SPRITES)
		mlx_destroy_image(vars->mlx, vars->sprite[i].image.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars);
	exit(0);
}
