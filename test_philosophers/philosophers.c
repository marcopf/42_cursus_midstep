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

double	get_msec(struct timeval start, struct timeval end)
{
	double	second;
	double	microsecond;

	second = end.tv_sec - start.tv_sec;
	microsecond = ((second * 1000000) + end.tv_usec) - start.tv_usec;
	return (microsecond / 1000);
}

double	get_ts(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return ((ts.tv_sec * 1000) + ts.tv_usec / 1000);

}

void	set_to_eat(int val)
{
	printf("eating...\n");
	sleep(val);
}

void	set_to_sleep(t_philo *philo)
{
	printf("%.0f-il filosofo %d è andato a dormire\n", get_ts(philo->ts), philo->id);
	usleep(philo->back->time_to_sleep * 1000);
}

void	set_to_think(int val)
{
	printf("thinking...\n");
	sleep(val);
}

void my_sleep(int i, int ms)
{
	while (--i)
	{
		usleep(ms);
	}
}

int	try_to_eat(t_env *env, int i)
{
	//controllare il caso 1 filosofo
	if (i <= env->arr_len - 2)
	{
		pthread_mutex_lock(&env->philo_arr[i].fork);
		pthread_mutex_lock(&env->philo_arr[i + 1].fork);
		printf("%.0f-il filosofo %d ha preso le forchette\n", get_ts(env->philo_arr[i].ts), i);
		usleep(env->time_to_eat * 1000);
		printf("%.0f-il filosofo %d ha mangiato\n", get_ts(env->philo_arr[i].ts), i);
		pthread_mutex_unlock(&env->philo_arr[i].fork);
		pthread_mutex_unlock(&env->philo_arr[i + 1].fork);	
	}
	else if (i == env->arr_len - 1)
	{
		pthread_mutex_lock(&env->philo_arr[i].fork);
		pthread_mutex_lock(&env->philo_arr[0].fork);
		printf("%.0f-il filosofo %d ha preso le forchette\n", get_ts(env->philo_arr[i].ts), i);
		usleep(env->time_to_eat * 1000);
		printf("%.0f-il filosofo %d ha mangiato\n", get_ts(env->philo_arr[i].ts), i);
		pthread_mutex_unlock(&env->philo_arr[i].fork);
		pthread_mutex_unlock(&env->philo_arr[0].fork);	
	}
	return (i);
}

void	*routine(void *void_philo)
{
	t_philo			*philo;
	struct timeval	start;
	struct timeval	end;

	philo = (t_philo *)void_philo;
	gettimeofday(&start, NULL);
	try_to_eat(philo->back, philo->id);
	gettimeofday(&end, NULL);
	set_to_sleep(philo);
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
}
