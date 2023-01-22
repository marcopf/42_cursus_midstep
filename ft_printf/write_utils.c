/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:38:27 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/22 16:38:40 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	c_write(int fd, char *c, int n)
{
	static int	i = 0;

	i += n;
	if (n == 0)
		return (i);
	write(fd, c, n);
	return (i);
}
