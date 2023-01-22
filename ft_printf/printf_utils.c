/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:40:46 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/22 16:49:35 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_u_putnbr(unsigned int n)
{
	unsigned int		temp;
	char				c;

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

void	router(va_list *args, char c)
{
	if (c == 'd')
		ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		ft_putstr(va_arg(*args, char *));
	else if (c == 'c')
		ft_putchar(va_arg(*args, int));
	else if (c == '%')
		c_write(1, "%", 1);
	else if (c == 'i')
		ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		ft_u_putnbr(va_arg(*args, int));
	else if (c == 'x')
		hex(va_arg(*args, int), 0);
	else if (c == 'X')
		hex(va_arg(*args, int), 1);
	else if (c == 'p' || c == 'P')
		write_ptr((unsigned long long)va_arg(*args, void *));
}

int	get_specifier(char *str, va_list *args)
{
	int		j;
	int		i;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			router(args, str[i]);
			j++;
		}
		else
			c_write(1, &str[i], 1);
	}
	return (0);
}
