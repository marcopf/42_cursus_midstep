/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:51 by marco             #+#    #+#             */
/*   Updated: 2023/03/05 21:15:01 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philosophers.h"

static unsigned long	ft_dim(unsigned long n)
{
	double	dim;

	if (!n)
		return (1);
	dim = 0;
	if (n < 0)
		dim++;
	while (n)
	{
		n /= 10;
		dim++;
	}
	return (dim);
}

static unsigned long	ft_abs(unsigned long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(unsigned long n)
{
	char			*num;
	size_t			dim;
	unsigned long	m;

	dim = ft_dim(n);
	num = (char *) malloc((dim + 1) * sizeof (char));
	if (!num)
		return (0);
	num[dim] = 0;
	m = n;
	while (dim--)
	{
		num[dim] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	if (m < 0)
		num[0] = '-';
	return (num);
}
