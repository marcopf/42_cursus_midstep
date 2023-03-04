/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:35 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/04 08:50:14 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include <sys/time.h>
#include <time.h>

struct	s_env;

typedef struct s_philo{
	pthread_t		philo;
	pthread_t		clock;
	pthread_mutex_t	m_clock;
	pthread_mutex_t	eat;
	pthread_mutex_t	fork;
	struct timeval	ts;
	int				eat_count;
	double			time_elapsed;
	double			init_ts;
	double			sleep_timestamp;
	struct timeval	sleep_ts;
	int				id;
	struct s_env	*back;
}	t_philo;

typedef struct s_env{
	t_philo			*philo_arr;
	int				arr_len;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				barrier;
	pthread_mutex_t	mutex;
}	t_env;

int	ft_atoi(const char *str);
double	get_msec(struct timeval start, struct timeval end);
double	get_ts_micro(struct timeval ts);
double	get_ts(struct timeval ts);
void	ft_mssleep(int val, t_philo *philo);
void	*time_calc(void *void_philo);
void	try_to_eat(t_env *env, int i);
void	set_to_sleep(t_philo *philo);
int		threads_setter(char **argv, t_env *env);
void	thread_wait(t_env *env);
void	destroy_all_mutex(t_env *env);
void	*routine(void *void_philo);

#endif
