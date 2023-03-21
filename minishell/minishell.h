/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:47:06 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/20 14:13:49 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

typedef struct s_var
{
	char			*name;
	char			*value;
	int				export;
	struct s_var	*next;
}	t_var;

int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *src);

void	ft_varclear(t_var **var);
void	ft_vardelone(t_var *var);
void	ft_varedit(t_var **var, char *name, char *value, int export);
void	ft_varadd_front(t_var **var, char *name, char *value, int export);
t_var	*ft_varsearch(t_var *var, char *name);

#endif