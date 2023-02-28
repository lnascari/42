/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/28 14:29:37 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_death(t_philo *philo)
{
	long	time;

	if (philo->info->time_to_eat
		+ philo->info->time_to_sleep >= philo->info->time_to_die)
	{
		usleep((philo->info->time_to_die - philo->info->time_to_eat) * 1000);
		time = philo->last_meal + philo->info->time_to_die * 1000;
		philo->info->death++;
		if (philo->info->death == 1)
			printf ("%ld\t%d is dead\n", time / 1000, philo->pos);
	}
}

void	check_death(t_philo *philo)
{
	struct timeval	tv;
	long			time;
	long			ltime;
	long			rtime;
	long			maxtime;

	gettimeofday(&tv, 0);
	time = tv.tv_sec * 1000000 + tv.tv_usec - philo->info->time;
	ltime = *philo->llast_meal + philo->info->time_to_eat * 1000;
	rtime = *philo->rlast_meal + philo->info->time_to_eat * 1000;
	maxtime = rtime;
	if (ltime > rtime)
		maxtime = ltime;
	if (maxtime > time)
	{
		if (maxtime > philo->last_meal + philo->info->time_to_die * 1000)
		{
			maxtime = philo->last_meal + philo->info->time_to_die * 1000;
			usleep(maxtime - time);
			philo->info->death++;
			if (philo->info->death == 1)
				printf ("%ld\t%d is dead\n", maxtime / 1000, philo->pos);
		}
	}
}

void	*routine(void *arg)
{
	struct timeval	tv;
	t_philo			*philo;

	philo = (t_philo *) arg;
	while (philo->number_of_times_each_philosopher_must_eat--)
	{
		gettimeofday(&tv, 0);
		printf ("%ld\t%d is thinking\n", (tv.tv_sec * 1000000
				+ tv.tv_usec - philo->info->time) / 1000, philo->pos);
		check_death(philo);
		if (philo->info->death)
			return (0);
		pthread_mutex_lock(&philo->rfork);
		check_death(philo);
		if (philo->info->death)
			return (0);
		gettimeofday(&tv, 0);
		printf ("%ld\t%d has taken a fork\n", (tv.tv_sec * 1000000
				+ tv.tv_usec - philo->info->time) / 1000, philo->pos);
		pthread_mutex_lock(philo->lfork);
		check_death(philo);
		if (philo->info->death)
			return (0);
		gettimeofday(&tv, 0);
		printf ("%ld\t%d has taken a fork\n", (tv.tv_sec * 1000000
				+ tv.tv_usec - philo->info->time) / 1000, philo->pos);
		gettimeofday(&tv, 0);
		philo->last_meal = tv.tv_sec * 1000000 + tv.tv_usec - philo->info->time;
		if (philo->info->death)
			return (0);
		printf ("%ld\t%d is eating\n", philo->last_meal / 1000, philo->pos);
		usleep(philo->info->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		gettimeofday(&tv, 0);
		if (philo->info->death)
			return (0);
		printf("%ld\t%d is sleeping\n", (tv.tv_sec * 1000000
				+ tv.tv_usec - philo->info->time) / 1000, philo->pos);
		sleep_death(philo);
		usleep(philo->info->time_to_sleep * 1000);
		if (philo->info->death)
			return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct timeval	tv;
	t_philo			*philo;
	t_info			info;
	int				i;
	int				n;

	if (argc == 5 || argc == 6)
	{
		info.number_of_philosophers = ft_atoi(argv[1]);
		info.time_to_die = ft_atoi(argv[2]);
		info.time_to_eat = ft_atoi(argv[3]);
		info.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			n = ft_atoi(argv[5]);
		else
			n = -1;
		philo = malloc(sizeof(t_philo) * info.number_of_philosophers);
		gettimeofday(&tv, 0);
		info.time = tv.tv_sec * 1000000 + tv.tv_usec;
		info.death = 0;
		i = -1;
		while (++i < info.number_of_philosophers)
		{
			pthread_mutex_init(&philo[i].rfork, 0);
			if (i == info.number_of_philosophers - 1)
				philo[i].lfork = &philo[0].rfork;
			else
				philo[i].lfork = &philo[i + 1].rfork;
			if (i == info.number_of_philosophers - 1)
				philo[i].llast_meal = &philo[0].last_meal;
			else
				philo[i].llast_meal = &philo[i + 1].last_meal;
			if (i == 0)
				philo[i].rlast_meal = &philo[info.number_of_philosophers
					- 1].last_meal;
			else
				philo[i].rlast_meal = &philo[i - 1].last_meal;
			philo[i].last_meal = 0;
			philo[i].pos = i + 1;
			philo[i].info = &info;
			philo[i].number_of_times_each_philosopher_must_eat = n;
		}
		i = 0;
		while (i < info.number_of_philosophers)
		{
			pthread_create(&philo[i].thread, 0, &routine, philo + i);
			i += 2;
			usleep(1);
		}
		i = 1;
		while (i < info.number_of_philosophers)
		{
			pthread_create(&philo[i].thread, 0, &routine, philo + i);
			i += 2;
			usleep(1);
		}
		i = -1;
		while (++i < info.number_of_philosophers)
			pthread_join(philo[i].thread, 0);
		free(philo);
	}
}
