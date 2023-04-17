/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:29:23 by gpaoline          #+#    #+#             */
/*   Updated: 2023/04/17 13:28:14 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0 && s2[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	ft_free_split(char **s, int all)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	if (all)
		free(s);
}

void	ft_free_struct(t_red *orders, int pipes)
{
	int	i;

	i = -1;
	while (++i < pipes + 1)
	{
		close(orders[i].s_in);
		close(orders[i].s_out);
		free(orders[i].input_file);
		free(orders[i].output_file);
		if (orders[i].s)
			ft_free_split(orders[i].s, 1);
	}
	free(orders);
}

void	ft_free_and_exit(t_red *orders, char *str, int pipes)
{
	ft_free_struct(orders, pipes);
	free(str);
	ft_varclear(&g_var);
	rl_clear_history();
	exit(0);
}
