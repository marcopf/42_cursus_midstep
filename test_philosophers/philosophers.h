/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:45:35 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/27 16:40:21 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct e_philo{
	pthread_t		*philo_arr;
	pthread_mutex_t	mutex;
	int				arr_len;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
}	t_philo;

int	ft_atoi(const char *str);

#endif
