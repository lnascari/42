/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:55:29 by lnascari          #+#    #+#             */
/*   Updated: 2023/04/12 11:31:46 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000000 + tv.tv_usec - philo->info->time) / 1000);
}

int	get_set(t_philo *philo, int set, int last_meal)
{
	int	value;

	value = 0;
	if (last_meal)
	{
		pthread_mutex_lock(&philo->lmmutex);
		if (set)
			philo->last_meal = get_time(philo);
		else
			value = philo->last_meal;
		pthread_mutex_unlock(&philo->lmmutex);
	}
	else
	{
		pthread_mutex_lock(&philo->notepmemutex);
		value = philo->notepme;
		if (set)
		{
			philo->notepme--;
			value++;
		}
		pthread_mutex_unlock(&philo->notepmemutex);
	}
	return (value);
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
			if (get_set(&info->philo[i], 0, 1) + info->ttd < get_time(info->philo))
			{
				pthread_mutex_lock(&info->dmutex);
				info->death++;
				if (get_set(&info->philo[i], 0, 0) != -1)
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
		get_set(philo, 1, 1);
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
