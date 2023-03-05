/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:35 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/05 21:15:11 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

struct	s_env;

typedef struct s_philo{
	int				fork_index;
	int				eat_count;
	double			init_ts;
	double			sleep_timestamp;
	int				id;
	char			*id_str;
	pthread_t		philo;
	pthread_t		clock;
	pthread_mutex_t	fork;
	struct timeval	ts;
	struct timeval	sleep_ts;
	struct s_env	*back;
}	t_philo;

typedef struct s_env{
	int				arr_len;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				philosopher_n;
	int				how_many_eat;
	int				is_alive;
	double			origin_time;
	t_philo			*philo_arr;
	pthread_mutex_t	eating;
	pthread_mutex_t	writing;
}	t_env;

int		ft_atoi(const char *str);
void	ft_mssleep(int val, t_philo *philo);
void	*time_calc(void *void_philo);
int		env_setter(char **argv, int argc, t_env *env);
void	thread_wait(t_env *env);
void	destroy_all_mutex(t_env *env);
void	*philo_routine(void *void_philo);
char	*ft_itoa(unsigned long n);

#endif
