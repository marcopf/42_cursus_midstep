/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:29:20 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 09:37:58 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	small_sort_2(t_stacks *stacks)
{
	if (stacks->stack_a.list[0] > stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] < stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] < stacks->stack_a.list[2])
		sa(stacks, 1);
	else if (stacks->stack_a.list[0] > stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] > stacks->stack_a.list[2])
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (stacks->stack_a.list[0] > stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] < stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] > stacks->stack_a.list[2])
		ra(stacks, 1);
	else if (stacks->stack_a.list[0] < stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] > stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] > stacks->stack_a.list[2])
		rra(stacks, 1);
	else if (stacks->stack_a.list[0] < stacks->stack_a.list[1]
		&& stacks->stack_a.list[1] > stacks->stack_a.list[2]
		&& stacks->stack_a.list[0] < stacks->stack_a.list[2])
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
}

void	small_sort(t_stacks *stacks)
{
	if (stacks->stack_a.placed_number == 2)
	{
		if (stacks->stack_a.list[0] > stacks->stack_a.list[1])
			ra(stacks, 1);
	}
	if (stacks->stack_a.placed_number == 3)
		small_sort_2(stacks);
	free(stacks->stack_a.list);
	free(stacks->stack_b.list);
	exit(0);
}
