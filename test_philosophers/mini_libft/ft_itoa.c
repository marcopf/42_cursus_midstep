/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:51 by marco             #+#    #+#             */
/*   Updated: 2023/03/04 16:09:02 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philosophers.h"

static size_t	ft_dim(int n)
{
	size_t	dim;

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

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	dim;
	int		m;

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