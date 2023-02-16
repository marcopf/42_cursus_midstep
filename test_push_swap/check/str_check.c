/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:28:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/16 21:29:17 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	str_check(char *str, t_stacks *stacks)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
		{
			if (str[i] == '-')
			{
				if (str[i + 1] && !ft_isdigit(str[i + 1]))
					finish(stacks);
			}
			else
				finish(stacks);
		}
	}
	return (1);
}
