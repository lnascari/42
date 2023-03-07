/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:55:29 by lnascari          #+#    #+#             */
/*   Updated: 2023/03/07 10:37:23 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000000 + tv.tv_usec - philo->info->time) / 1000);
}

void	*check_death(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *) arg;
	while (!info->death && info->nop)
	{
		i = -1;
		while (++i < info->nop)
		{
			if (info->philo[i].last_meal + info->ttd < get_time(info->philo))
			{
				info->death++;
				if (info->philo[i].notepme != -1 && info->death == 1)
					printf ("%d\t%d is dead\n", get_time(info->philo), i + 1);
			}
		}
	}
	if (info->nop == 1)
		pthread_detach(info->philo[0].thread);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->notepme-- && !philo->info->death)
	{
		if (!philo->info->death)
			printf ("%d\t%d is thinking\n", get_time(philo), philo->pos);
		pthread_mutex_lock(&philo->rfork);
		if (!philo->info->death)
			printf ("%d\t%d has taken a fork\n", get_time(philo), philo->pos);
		pthread_mutex_lock(philo->lfork);
		if (!philo->info->death)
			printf ("%d\t%d has taken a fork\n", get_time(philo), philo->pos);
		philo->last_meal = get_time(philo);
		if (!philo->info->death)
			printf ("%d\t%d is eating\n", philo->last_meal, philo->pos);
		usleep(philo->info->tte * 1000);
		pthread_mutex_unlock(&philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		if (!philo->info->death)
			printf("%d\t%d is sleeping\n", get_time(philo), philo->pos);
		usleep(philo->info->tts * 1000);
	}
	return (0);
}
