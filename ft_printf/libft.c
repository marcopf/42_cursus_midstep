/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:23:14 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/24 13:41:21 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void	write_u_putnbr(unsigned int n)
{
	unsigned int		temp;
	char				c;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		temp = (n % 10) + '0';
		n = n / 10;
		write_u_putnbr(n);
		write(1, &temp, 1);
	}
}

int	ft_u_putnbr(unsigned int n)
{
	write_u_putnbr(n);
	return (ft_num_len(n));
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	else
	{
		i = 0;
		while (str[i])
			write(1, &str[i++], 1);
	}
	return (ft_strlen(str));
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
