/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 21:52:44 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	is_max(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_a.placed_number)
	{
		if (n < stacks->stack_a.list[i])
			return (0);
	}
	return (1);
}

int	is_min_greed(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_a.placed_number)
	{
		if (n > stacks->stack_a.list[i])
			return (0);
	}
	return (1);
}

int	is_in_between(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (i++ < stacks->stack_a.placed_number - 1)
	{
		if (is_max(stacks, stacks->stack_b.list[0]))
		{
			if (is_min_greed(stacks, stacks->stack_a.list[0]))
				return (i);
			while (stacks->stack_a.list[i] < stacks->stack_a.list[i + 1])
				i++;
			return (i + 1);
		}
		else if (is_min_greed(stacks, stacks->stack_b.list[0]))
		{
			while (stacks->stack_a.list[i] < stacks->stack_a.list[i + 1])
				i++;
			return (i + 1);
		}
		else if (stacks->stack_b.list[0] > stacks->stack_a.list[i]
			&& stacks->stack_b.list[0] < stacks->stack_a.list[i + 1])
			return (i + 1);
	}
	return (0);
}

void	push_all_b_greed(t_stacks *stacks)
{
	get_lis(stacks);
	while (stacks->stack_a.placed_number > stacks->lis.lis_len)
	{
		if (!is_in_lis(stacks->lis.lis, stacks->lis.lis_len,
				stacks->stack_a.list[0]))
			pb(stacks, 0, 1);
		else
			ra(stacks, 1);
	}
	while (stacks->stack_a.list[0] != is_min(stacks->stack_a.list,
			stacks->stack_a.placed_number))
		ra(stacks, 1);
	free(stacks->lis.lis);
}

void	greedy(char *argv)
{
	t_stacks	stacks_cpy;
	int			i;
	int			temp;

	fill_stack(&stacks_cpy, argv);
	push_all_b_greed(&stacks_cpy);
	while (stacks_cpy.stack_b.placed_number > 0)
	{
		temp = is_in_between(&stacks_cpy);
		while (temp--)
			ra(&stacks_cpy, 1);
		pa(&stacks_cpy, 0, 1);
	}
	while (stacks_cpy.stack_a.list[0] != is_min(stacks_cpy.stack_a.list,
			stacks_cpy.stack_a.placed_number))
		ra(&stacks_cpy, 0);
}
