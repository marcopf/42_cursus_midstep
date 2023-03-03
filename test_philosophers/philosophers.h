/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:35 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/03 16:01:49 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

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

#endif
