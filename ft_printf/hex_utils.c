/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:37:04 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/22 16:37:05 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hex(unsigned int n, int switcher)
{
	char	*set;
	int		temp;

	if (switcher)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (n < 16 && n >= 0)
	{
		temp = n % 16;
		c_write(1, &set[temp], 1);
	}
	else
	{
		temp = n % 16;
		n /= 16;
		hex(n, switcher);
		c_write(1, &set[temp], 1);
	}
}
