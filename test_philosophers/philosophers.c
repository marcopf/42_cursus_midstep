/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:46:56 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/04 08:48:43 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	pthread_mutex_lock(&((t_philo *)void_philo)->back->mutex);
	philo->back->barrier++;
	pthread_mutex_unlock(&((t_philo *)void_philo)->back->mutex);
	while (philo->back->barrier < philo->back->arr_len)
		;
	pthread_create(&philo->clock, 0, &time_calc, void_philo);
	while (42)
	{
		try_to_eat(philo->back, philo->id);
		set_to_sleep(philo);
		printf("%.0f-il filosofo %d sta pensando\n", get_ts(philo->ts), philo->id);
	}
	pthread_join(philo->clock, 0);
	pthread_mutex_destroy(&philo->m_clock);
	pthread_mutex_destroy(&philo->eat);
	return (0);
}

void	free_philo(t_env *env)
{
	free(env->philo_arr);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(struct s_env));
	pthread_mutex_init(&env->mutex, NULL);
	threads_setter(argv, env);
	thread_wait(env);
	free_philo(env);
	destroy_all_mutex(env);
	pthread_mutex_destroy(&env->mutex);
	free(env);
	// struct timeval time_temp;
	// double start, end;
	// start = get_ts_micro(time_temp);
	// ft_mssleep(200);
	// //printf("bhfjsb%.0fvhskjbhvkjfbdgv%dkjbwdfvgjkfbsvkjsfbvkfsbvksfjbv\n", get_ts(time_temp), 4);
	// end = get_ts_micro(time_temp);
	// printf("%f -- %f\n\n", end - start, start);
}
