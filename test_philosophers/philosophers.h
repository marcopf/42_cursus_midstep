/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:35 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/01 14:52:55 by mpaterno         ###   ########.fr       */
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
	int				id;
	int				fork;
	struct s_env	*back;
}	t_philo;

typedef struct s_env{
	t_philo			*philo_arr;
	int				arr_len;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	pthread_mutex_t	mutex;
}	t_env;

int	ft_atoi(const char *str);

#endif
