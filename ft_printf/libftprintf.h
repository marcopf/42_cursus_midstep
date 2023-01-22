/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:39:46 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/22 16:53:52 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char *str, ...);
int		c_write(int fd, char *c, int n);
void	write_ptr(unsigned long long int n);
void	hex(unsigned int n, int switcher);
void	ft_u_putnbr(unsigned int n);
int		get_specifier(char *str, va_list *args);
void	ft_putnbr(int n);
void	ft_putstr(const char *str);
void	ft_putchar(const char c);

# endif
