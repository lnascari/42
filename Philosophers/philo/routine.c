/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:55:29 by lnascari          #+#    #+#             */
/*   Updated: 2023/04/03 12:35:52 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000000 + tv.tv_usec - philo->info->time) / 1000);
}

int	is_dead(t_info *info)
{
	int	bool;

	pthread_mutex_lock(&info->dmutex);
	if (info->death)
		bool = 1;
	else
		bool = 0;
	pthread_mutex_unlock(&info->dmutex);
	return (bool);
}

void	*check_death(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *) arg;
	if (info->nop == 1)
		printf ("0\t1 has taken a fork\n");
	while (info->nop)
	{
		i = -1;
		while (++i < info->nop)
		{
			if (info->philo[i].last_meal + info->ttd < get_time(info->philo))
			{
				pthread_mutex_lock(&info->dmutex);
				info->death++;
				if (info->philo[i].notepme != -1)
					printf ("%d\t%d died\n", get_time(info->philo), i + 1);
				pthread_mutex_unlock(&info->dmutex);
				return (0);
			}
		}
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->notepme-- && philo->info->nop != 1 && !is_dead(philo->info))
	{
		if (!is_dead(philo->info))
			printf ("%d\t%d is thinking\n", get_time(philo), philo->pos);
		pthread_mutex_lock(&philo->rfork);
		if (!is_dead(philo->info))
			printf ("%d\t%d has taken a fork\n", get_time(philo), philo->pos);
		pthread_mutex_lock(philo->lfork);
		if (!is_dead(philo->info))
			printf ("%d\t%d has taken a fork\n", get_time(philo), philo->pos);
		philo->last_meal = get_time(philo);
		if (!is_dead(philo->info))
			printf ("%d\t%d is eating\n", get_time(philo), philo->pos);
		usleep(philo->info->tte * 1000);
		pthread_mutex_unlock(&philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		if (!is_dead(philo->info))
			printf ("%d\t%d is sleeping\n", get_time(philo), philo->pos);
		usleep(philo->info->tts * 1000);
	}
	return (0);
}
