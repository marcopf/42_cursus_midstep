/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:35 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/05 10:01:47 by marco            ###   ########.fr       */
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
	pthread_mutex_t	fork;
	struct timeval	ts;
	int				fork_index;
	int				eat_count;
	double			init_ts;
	double			sleep_timestamp;
	struct timeval	sleep_ts;
	int				id;
	char			*id_str;
	struct s_env	*back;
}	t_philo;

typedef struct s_env{
	t_philo			*philo_arr;
	int				arr_len;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	double			origin_time;
	pthread_mutex_t	writing;
}	t_env;

int	ft_atoi(const char *str);
// double	get_msec(struct timeval start, struct timeval end);
// double	get_ts_micro(struct timeval ts);
void	ft_mssleep(int val, t_philo *philo);
void	*time_calc(void *void_philo);
int		threads_setter(char **argv, t_env *env);
void	thread_wait(t_env *env);
void	destroy_all_mutex(t_env *env);
void	*routine(void *void_philo);
char	*ft_itoa(int n);

#endif
