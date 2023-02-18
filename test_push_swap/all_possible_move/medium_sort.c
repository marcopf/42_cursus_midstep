/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:14:39 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 18:45:12 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_a.placed_number - 1)
	{
		if (stacks->stack_a.list[i] > stacks->stack_a.list[i + 1])
			return (0);
	}
	return (1);
}

void	medium_sort(t_stacks *stacks)
{
	if (!is_sorted(stacks))
	{
		pb(stacks, 0, 1);
		pb(stacks, 0, 1);
		small_sort_for_medium(stacks);
		sort(stacks);
		ascend(stacks);
	}
	else
	{
		free(stacks->stack_a.list);
		free(stacks->stack_b.list);
		exit(0);
	}
}
