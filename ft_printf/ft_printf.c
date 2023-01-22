/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:40:14 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/22 16:40:15 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char *str, ...)
{
	va_list	args;

	va_start(args, str);
	get_specifier(str, &args);
	va_end(args);
	return (c_write(0, 0, 0));
}
