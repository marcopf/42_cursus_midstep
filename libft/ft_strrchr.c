/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:32:36 by mpaterno          #+#    #+#             */
/*   Updated: 2023/01/16 12:32:36 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == c)
			ptr = (char *) s;
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (ptr);
}
