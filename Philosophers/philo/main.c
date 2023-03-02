/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/03/02 12:22:19 by lnascari         ###   ########.fr       */
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
				if (info->death == 1)
					printf ("%d\t%d is dead\n", get_time(info->philo), i + 1);
			}
		}
	}
	i = -1;
	while (++i < info->nop)
		pthread_detach(info->philo[i].thread);
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

int	main(int argc, char **argv)
{
	struct timeval	tv;
	t_info			info;
	int				i;
	int				n;

	if (argc == 5 || argc == 6)
	{
		info.nop = ft_atoi(argv[1]);
		info.ttd = ft_atoi(argv[2]);
		info.tte = ft_atoi(argv[3]);
		info.tts = ft_atoi(argv[4]);
		if (argc == 6)
			n = ft_atoi(argv[5]);
		else
			n = -1;
		info.philo = malloc(sizeof(t_philo) * info.nop);
		gettimeofday(&tv, 0);
		info.time = tv.tv_sec * 1000000 + tv.tv_usec;
		info.death = 0;
		i = -1;
		while (++i < info.nop)
		{
			pthread_mutex_init(&info.philo[i].rfork, 0);
			if (i == info.nop - 1)
				info.philo[i].lfork = &info.philo[0].rfork;
			else
				info.philo[i].lfork = &info.philo[i + 1].rfork;
			info.philo[i].last_meal = 0;
			info.philo[i].pos = i + 1;
			info.philo[i].info = &info;
			info.philo[i].notepme = n;
		}
		pthread_create(&info.dthread, 0, &check_death, &info);
		i = 0;
		while (i < info.nop)
		{
			pthread_create(&info.philo[i].thread, 0, &routine, info.philo + i);
			i += 2;
			usleep(1);
		}
		i = 1;
		while (i < info.nop)
		{
			pthread_create(&info.philo[i].thread, 0, &routine, info.philo + i);
			i += 2;
			usleep(1);
		}
		pthread_join(info.dthread, 0);
		i = -1;
		while (++i < info.nop)
			pthread_join(info.philo[i].thread, 0);
		free(info.philo);
	}
}
