/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:46:56 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/03 16:50:42 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <time.h>

double	get_msec(struct timeval start, struct timeval end)
{
	double	second;
	double	microsecond;

	second = end.tv_sec - start.tv_sec;
	microsecond = ((second * 1000000) + end.tv_usec) - start.tv_usec;
	return (microsecond / 1000);
}

double	get_ts_micro(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return ((ts.tv_sec * 1000000) + ts.tv_usec);
}

double	get_ts(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return ((ts.tv_sec * 1000) + ts.tv_usec / 1000);
}

void	ft_mssleep(int val, t_philo *philo)
{
	philo->sleep_timestamp = get_ts(philo->sleep_ts);
	while ((get_ts(philo->sleep_ts) - philo->sleep_timestamp) < val)
		;
}

void	set_to_sleep(t_philo *philo)
{
	printf("%.0f-il filosofo %d è andato a dormire\n", get_ts(philo->ts), philo->id);
	ft_mssleep(philo->back->time_to_sleep, philo);
}

int	try_to_eat(t_env *env, int i)
{
	if (i <= env->arr_len - 2)
	{
		pthread_mutex_lock(&env->philo_arr[i].fork);
	pthread_mutex_lock(&env->philo_arr[i + 1].fork);
		pthread_mutex_lock(&env->philo_arr[i].m_clock);
		env->philo_arr[i].time_elapsed = 0;
		env->philo_arr[i].init_ts = get_ts(env->philo_arr[i].ts);
		pthread_mutex_unlock(&env->philo_arr[i].m_clock);
		printf("%.0f-il filosofo %d ha preso le forchette\n", get_ts(env->philo_arr[i].ts), i);
		pthread_mutex_lock(&env->philo_arr[i].eat);
		ft_mssleep(env->time_to_eat, &env->philo_arr[i]);
		pthread_mutex_unlock(&env->philo_arr[i].eat);
		printf("%.0f-il filosofo %d ha mangiato\n", get_ts(env->philo_arr[i].ts), i);
		pthread_mutex_unlock(&env->philo_arr[i].fork);
		pthread_mutex_unlock(&env->philo_arr[i + 1].fork);
	}
	else if (i == env->arr_len - 1)
	{
		pthread_mutex_lock(&env->philo_arr[i].fork);
		pthread_mutex_lock(&env->philo_arr[0].fork);
		pthread_mutex_lock(&env->philo_arr[i].m_clock);
		env->philo_arr[i].time_elapsed = 0;
		env->philo_arr[i].init_ts = get_ts(env->philo_arr[i].ts);
		pthread_mutex_unlock(&env->philo_arr[i].m_clock);
		printf("%.0f-il filosofo %d ha preso le forchette\n", get_ts(env->philo_arr[i].ts), i);
		pthread_mutex_lock(&env->philo_arr[i].eat);
		ft_mssleep(env->time_to_eat, &env->philo_arr[i]);
		pthread_mutex_unlock(&env->philo_arr[i].eat);
		printf("%.0f-il filosofo %d ha mangiato\n", get_ts(env->philo_arr[i].ts), i);
		pthread_mutex_unlock(&env->philo_arr[i].fork);
		pthread_mutex_unlock(&env->philo_arr[0].fork);
	}
	return (i);
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
		usleep(1000);
	}
	printf("%.0f-il filosofo %d è morto\n", get_ts(philo->ts), philo->id);
	exit(0);
}

void	*routine(void *void_philo)
{
	t_philo			*philo;

	pthread_mutex_lock(&((t_philo *)void_philo)->back->mutex);
	philo = (t_philo *)void_philo;
	pthread_mutex_unlock(&((t_philo *)void_philo)->back->mutex);
	pthread_mutex_init(&philo->m_clock, 0);
	pthread_mutex_init(&philo->eat, 0);
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

int	thread_setter(char **argv, t_env *env)
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
		env->philo_arr[i].back = env;
		env->philo_arr[i].id = i;
		env->philo_arr[i].eat_count = 0;
		pthread_mutex_init(&env->philo_arr[i].fork, NULL);
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

void	destroy_all_mutex(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->arr_len)
		pthread_mutex_destroy(&env->philo_arr[i].fork);	
}

void	free_philo(t_env *env)
{
	free(env->philo_arr);
}

int	main(int argc, char **argv)
{
	t_env	env;

	pthread_mutex_init(&env.mutex, NULL);
	thread_setter(argv, &env);
	thread_wait(&env);
	free_philo(&env);
	destroy_all_mutex(&env);
	pthread_mutex_destroy(&env.mutex);
	// struct timeval time_temp;
	// double start, end;
	// start = get_ts(time_temp);
	// printf("bhfjsbvhskjbhvkjfbdgvkjbwdfvgjkfbsvkjsfbvkfsbvksfjbv\n");
	// end = get_ts(time_temp);
	// printf("%f -- %f\n\n", end - start, start);
}
