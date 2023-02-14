/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnascari <lnascari@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:20:25 by lnascari          #+#    #+#             */
/*   Updated: 2023/02/14 13:22:18 by lnascari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void*	routine(void* arg)
{
}

int	main(int argc, char **argv)
{
	philo_t philo;
	int		i;

	if (argc == 5 || argc == 6)
	{
		
		philo.number_of_philosophers = ft_atoi(argv[1]);
		philo.threads = malloc(sizeof(pthread_t) * philo.number_of_philosophers);
		i = -1;
		while (++i < philo.number_of_philosophers)
			pthread_create(philo.threads + i, 0, &routine, 0);
		philo.lock = PTHREAD_MUTEX_INITIALIZER;
		if (argc == 6)
			philo.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			philo.number_of_times_each_philosopher_must_eat = -1;
		while (philo.number_of_times_each_philosopher_must_eat)
		{
			while ()

			
		}
		
	}
}
