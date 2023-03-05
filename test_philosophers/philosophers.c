/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:46:56 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/04 21:27:06 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(struct s_env));
	pthread_mutex_init(&env->writing, NULL);
	threads_setter(argv, env);
	thread_wait(env);
	free(env->philo_arr);
	destroy_all_mutex(env);
	pthread_mutex_destroy(&env->writing);
	free(env);
	// struct timeval time_temp;
	// double start, end;
	// start = get_ts_micro(time_temp);
	// end = get_ts_micro(time_temp);
	// printf("%f\n\n", end - start);
}
