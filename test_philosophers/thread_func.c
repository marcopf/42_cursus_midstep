/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:48:18 by marco             #+#    #+#             */
/*   Updated: 2023/03/04 08:48:46 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thread_init(t_env *env, int i)
{
	pthread_mutex_init(&env->philo_arr[i].fork, NULL);
	pthread_mutex_init(&env->philo_arr[i].m_clock, 0);
	pthread_mutex_init(&env->philo_arr[i].eat, 0);
	env->philo_arr[i].back = env;
	env->philo_arr[i].id = i;
	env->philo_arr[i].eat_count = 0;
}

int	threads_setter(char **argv, t_env *env)
{
	int	i;

	i = -1;
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->arr_len = ft_atoi(argv[1]);
	env->barrier = 0;
	env->philo_arr = (t_philo *) malloc(sizeof(t_philo) * env->arr_len);
	while (++i < env->arr_len)
	{
		thread_init(env, i);
		if (pthread_create(&env->philo_arr[i].philo, NULL, routine,
				(void *)(env->philo_arr + i)) != 0)
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

void	destroy_all_mutex(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->arr_len)
		pthread_mutex_destroy(&env->philo_arr[i].fork);	
}