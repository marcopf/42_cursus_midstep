/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:37:39 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/22 16:38:06 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	int		temp;
	char	c;

	if (n == -2147483648)
		c_write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			c_write(1, "-", 1);
		}
		if (n <= 9)
		{
			c = n + '0';
			c_write(1, &c, 1);
		}
		else
		{
			temp = (n % 10) + '0';
			n = n / 10;
			ft_putnbr(n);
			c_write(1, (char *)&temp, 1);
		}
	}
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		c_write(1, "(null)", 6);
		return ;
	}
	while (str[i])
		c_write(1, (char *)&str[i++], 1);
}

void	ft_putchar(const char c)
{
	c_write(1, (char *)&c, 1);
}
