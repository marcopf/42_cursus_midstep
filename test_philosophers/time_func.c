/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:41:42 by marco             #+#    #+#             */
/*   Updated: 2023/03/04 08:41:58 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	while ((get_ts(philo->sleep_ts) - philo->sleep_timestamp) <= val)
		;
}