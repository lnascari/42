/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:55:29 by lnascari          #+#    #+#             */
/*   Updated: 2023/03/09 13:53:57 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * 1000000 + tv.tv_usec - philo->info->time) / 1000);
}

void	print_msg(int time, int n, char *msg, t_info *info)
{
	pthread_mutex_lock(&info->dmutex);
	if (!info->death)
		printf ("%d\t%d %s\n", time, n, msg);
	pthread_mutex_unlock(&info->dmutex);
}

void	*check_death(void *arg)
{
	t_info	*info;
	int		i;

	info = (t_info *) arg;
	if (info->nop == 1)
		printf("0\t1 has taken a fork\n");
	while (!info->death && info->nop)
	{
		i = -1;
		while (++i < info->nop)
		{
			if (info->philo[i].last_meal + info->ttd < get_time(info->philo))
			{
				pthread_mutex_lock(&info->dmutex);
				info->death++;
				if (info->philo[i].notepme != -1 && info->death == 1)
					printf ("%d\t%d died\n", get_time(info->philo), i + 1);
				pthread_mutex_unlock(&info->dmutex);
			}
		}
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->notepme-- && !philo->info->death && philo->info->nop != 1)
	{
		print_msg(get_time(philo), philo->pos, "is thinking", philo->info);
		pthread_mutex_lock(&philo->rfork);
		print_msg(get_time(philo), philo->pos, "has taken a fork", philo->info);
		pthread_mutex_lock(philo->lfork);
		print_msg(get_time(philo), philo->pos, "has taken a fork", philo->info);
		philo->last_meal = get_time(philo);
		print_msg(get_time(philo), philo->pos, "is eating", philo->info);
		usleep(philo->info->tte * 1000);
		pthread_mutex_unlock(&philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		print_msg(get_time(philo), philo->pos, "is sleeping", philo->info);
		usleep(philo->info->tts * 1000);
	}
	return (0);
}
