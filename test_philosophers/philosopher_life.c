/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:44:31 by marco             #+#    #+#             */
/*   Updated: 2023/03/05 10:07:52 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static double	get_ts(struct timeval ts)
{
	gettimeofday(&ts, 0);
	return (((ts.tv_sec * 1000) + ts.tv_usec / 1000));
}

static void    philo_say(const char *str, t_philo *philo)
{
    char    *ts;

    ts = ft_itoa(get_ts(philo->ts) - philo->back->origin_time);
	pthread_mutex_lock(&philo->back->writing);
    printf("%s %s %s\n", ts, philo->id_str, str);
	pthread_mutex_unlock(&philo->back->writing);
    free(ts);
}

static void	try_to_eat(t_env *env, int i)
{
    pthread_mutex_lock(&env->philo_arr[env->philo_arr[i].fork_index].fork);
	philo_say("forchetta", &env->philo_arr[i]);
	pthread_mutex_lock(&env->philo_arr[i].fork);
	env->philo_arr[i].init_ts = get_ts(env->philo_arr[i].ts);
    philo_say("forchetta", &env->philo_arr[i]);
    philo_say("mangiando", &env->philo_arr[i]);
	usleep(env->time_to_eat * 1000);
    pthread_mutex_unlock(&env->philo_arr[env->philo_arr[i].fork_index].fork);
	pthread_mutex_unlock(&env->philo_arr[i].fork);
}

void	*time_calc(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	philo->init_ts = get_ts(philo->ts);
	while ((get_ts(philo->ts) - philo->init_ts) <= philo->back->time_to_die + 1)
		usleep(100);
    philo_say("è morto", philo);
    exit(0);
}

void	*routine(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
    if (philo->id % 2 == 0)
        usleep((philo->back->time_to_die / 50) * 1000);
	if (pthread_create(&philo->clock, 0, &time_calc, void_philo) != 0)
		return (0);
	pthread_detach(philo->clock);
	usleep(100);
	while (42)
	{
		try_to_eat(philo->back, philo->id);
        philo_say("dormire", philo);
		usleep(philo->back->time_to_sleep * 1000);
        philo_say("pensando", philo);
	}
	return (0);
}