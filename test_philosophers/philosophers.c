/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:46:56 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/27 16:57:27 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <time.h>

void	set_to_eat(int val)
{
	printf("eating...\n");
	sleep(val);
}

void	set_to_sleep(int val)
{
	printf("sleeping...\n");
	sleep(val);
}

void	set_to_think(int val)
{
	printf("thinking...\n");
	sleep(val);
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	pthread_mutex_lock(&philo->mutex);
	printf("hey\n");
	set_to_eat(philo->time_to_eat);
	printf("ho detto heyyy\n");
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

int	thread_setter(char **argv, t_philo *philo)
{
	int	i;

	i = -1;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->arr_len = ft_atoi(argv[1]);
	philo->philo_arr = (pthread_t *) malloc(sizeof(pthread_t) * philo->arr_len);
	while (++i < philo->arr_len)
	{
		if (pthread_create(&philo->philo_arr[i], NULL, &routine,
				(void *)philo) != 0)
			return (-1);
	}
	return (0);
}

void	thread_wait(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->arr_len)
		pthread_join(philo->philo_arr[i], NULL);
}

void	free_philo(t_philo *philo)
{
	free(philo->philo_arr);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	pthread_mutex_init(&philo.mutex, NULL);
	thread_setter(argv, &philo);
	thread_wait(&philo);
	free_philo(&philo);
	pthread_mutex_destroy(&philo.mutex);
}
