/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:48:18 by marco             #+#    #+#             */
/*   Updated: 2023/03/05 10:01:10 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static double	get_ts(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return (((ts.tv_sec * 1000) + ts.tv_usec / 1000));
}

void	thread_init(t_env *env, int i)
{
	pthread_mutex_init(&env->philo_arr[i].fork, NULL);
	env->philo_arr[i].back = env;
	env->philo_arr[i].id = i;
    env->philo_arr[i].id_str = ft_itoa(i + 1);
    env->philo_arr[i].eat_count = 0;
    if (i == env->arr_len - 1)
        env->philo_arr[i].fork_index = 0;
    else
        env->philo_arr[i].fork_index = i + 1;
}

int	threads_setter(char **argv, t_env *env)
{
	int            i;
    struct timeval ts;

	i = -1;
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->arr_len = ft_atoi(argv[1]);
	env->philo_arr = (t_philo *) malloc(sizeof(t_philo) * env->arr_len);
    env->origin_time = get_ts(ts);
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