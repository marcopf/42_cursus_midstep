/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:46:56 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/01 17:04:14 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
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

int	try_to_eat(t_env *env, int i)
{
	if (i <= env->arr_len - 2)
	{
		while (42)
		{
			if (env->philo_arr[i].fork && env->philo_arr[i + 1].fork)
			{
				env->philo_arr[i].fork = 0;
				env->philo_arr[i + 1].fork = 0;
				usleep(env->time_to_eat);
				env->philo_arr[i].fork = 1;
				env->philo_arr[i + 1].fork = 1;
				return (1);
			}
			usleep(1);
		}
	}
	else if (i == env->arr_len - 1)
	{
		while (42)
		{
			if (env->philo_arr[i].fork && env->philo_arr[0].fork)
			{
				env->philo_arr[i].fork = 0;
				env->philo_arr[0].fork = 0;
				usleep(env->time_to_eat);
				env->philo_arr[i].fork = 1;
				env->philo_arr[0].fork = 1;
				return (1);
			}
			usleep(1);
		}		
	}
	return (i);
}

void	*routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (try_to_eat(philo->back, philo->id) == 1)
	{
		printf("sono il filosofo %d e ho mangiato\n", philo->id);
	}
	else
	{
		printf("sono il filosofo %d e non ho mangiato\n", philo->id);
	}
	return (0);
}

int	thread_setter(char **argv, t_env *env)
{
	int	i;

	i = -1;
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->arr_len = ft_atoi(argv[1]);
	env->philo_arr = (t_philo *) malloc(sizeof(t_philo) * env->arr_len);
	while (++i < env->arr_len)
	{
		env->philo_arr[i].back = env;
		env->philo_arr[i].id = i;
		env->philo_arr[i].fork = 1;
		if (pthread_create(&env->philo_arr[i].philo, NULL, &routine,
				(void *)&env->philo_arr[i]) != 0)
			return (-1);
	}
	return (0);
}

void	thread_wait(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->arr_len)
		pthread_join(env->philo_arr[i].philo, NULL);
}

void	free_philo(t_env *env)
{
	free(env->philo_arr);
}

int	main(int argc, char **argv)
{
	t_env	env;
	struct timeval start, end;

	gettimeofday(&start, NULL);
	sleep(1);
	gettimeofday(&end, NULL);
	printf("%d\n", end.tv_ - start.tv_usec);
	pthread_mutex_init(&env.mutex, NULL);
	thread_setter(argv, &env);
	thread_wait(&env);
	free_philo(&env);
	pthread_mutex_destroy(&env.mutex);
}
