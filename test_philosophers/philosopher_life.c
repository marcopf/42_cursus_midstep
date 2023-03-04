/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:44:31 by marco             #+#    #+#             */
/*   Updated: 2023/03/04 08:55:22 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_to_sleep(t_philo *philo)
{
	printf("%.0f-il filosofo %d è andato a dormire\n", get_ts(philo->ts), philo->id);
	ft_mssleep(philo->back->time_to_sleep, philo);
}

void	try_to_eat(t_env *env, int i)
{
	int	index;

	index = i + 1;
	if (i == env->arr_len - 1)
		index = 0;
    printf("%.0f-il filosofo %d sta provando a prendere le forchette\n", get_ts(env->philo_arr[i].ts), i);
	pthread_mutex_lock(&env->philo_arr[i].fork);
	pthread_mutex_lock(&env->philo_arr[index].fork);
	printf("%.0f-il filosofo %d ha preso le forchette\n", get_ts(env->philo_arr[i].ts), i);
	pthread_mutex_lock(&env->philo_arr[i].m_clock);
	env->philo_arr[i].time_elapsed = 0;
	env->philo_arr[i].init_ts = get_ts(env->philo_arr[i].ts);
	pthread_mutex_unlock(&env->philo_arr[i].m_clock);
	printf("%.0f-il filosofo %d sta mangiando\n", get_ts(env->philo_arr[i].ts), i);
	pthread_mutex_lock(&env->philo_arr[i].eat);
	ft_mssleep(env->time_to_eat, &env->philo_arr[i]);
	pthread_mutex_unlock(&env->philo_arr[i].eat);
	pthread_mutex_unlock(&env->philo_arr[index].fork);
	pthread_mutex_unlock(&env->philo_arr[i].fork);
}

void	*time_calc(void *void_philo)
{
	t_philo			*philo;

	pthread_mutex_lock(&((t_philo *)void_philo)->m_clock);
	philo = (t_philo *)void_philo;
	pthread_mutex_unlock(&((t_philo *)void_philo)->m_clock);
	philo->init_ts = get_ts(philo->ts);
	philo->time_elapsed = 0;
	while (philo->time_elapsed < philo->back->time_to_die)
	{
		pthread_mutex_lock(&philo->m_clock);
		pthread_mutex_lock(&philo->eat);
		philo->time_elapsed = get_ts(philo->ts) - philo->init_ts;
		pthread_mutex_unlock(&philo->eat);
		pthread_mutex_unlock(&philo->m_clock);
	}
	printf("%.0f-il filosofo %d è morto\n", get_ts(philo->ts), philo->id);
	exit(0);
}