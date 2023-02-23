/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:22:48 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/23 12:56:31 by lnascari         ###   ########.fr       */
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
	pthread_mutex_t	*lock;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				forks;
	long			time;
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	int			pos;
	int			number_of_times_each_philosopher_must_eat;
	t_info		*info;
}	t_philo;

int		ft_atoi(const char *str);

#endif