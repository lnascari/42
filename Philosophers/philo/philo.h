/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:22:48 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/15 15:05:40 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct philo_s
{
	pthread_t	thread;
}	philo_t;

typedef struct info_s
{
	pthread_mutex_t lock;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				forks;
	philo_t			*philo;
}	info_t;


int		ft_atoi(const char *str);

#endif