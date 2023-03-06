/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:22:48 by lnascari          #+#    #+#             */
/*   Updated: 2023/03/06 11:56:16 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	pthread_t		dthread;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				death;
	long			time;
	struct s_philo	*philo;
}	t_info;

typedef struct s_philo
{
	pthread_mutex_t	rfork;
	pthread_mutex_t	*lfork;
	pthread_t		thread;
	int				last_meal;
	int				pos;
	int				notepme;
	t_info			*info;
}	t_philo;

int		ft_atoi(const char *str);
void	*routine(void *arg);
void	*check_death(void *arg);

#endif