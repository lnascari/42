/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaoline <gpaoline@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:47:06 by gpaoline          #+#    #+#             */
/*   Updated: 2023/03/24 11:36:53 by gpaoline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
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

extern t_var	*g_var;

int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *src);
void	ft_free_split(char **s);

void	ft_varclear(t_var **var);
void	ft_vardelone(t_var **var, t_var *v);
void	ft_varedit(t_var **var, char *name, char *value, int export);
void	ft_varadd_front(t_var **var, char *name, char *value, int export);
t_var	*ft_varsearch(t_var *var, char *name);

void	space_in_quote(char *str);
void	del_quote(char *str);

void	spaces(char **s);

int		var_value(char *str, int export);
void	check_var(char **s);

void	ft_env(void);
void	ft_export(char **s);
void	ft_unset(char **s);
void	ft_exit(char **s, char *str);
void	ft_cd(char **s);

void	programs(char **s);

void	handler_int(int x);
void	handler_quit(int x);

#endif