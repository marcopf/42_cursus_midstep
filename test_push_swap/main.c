/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 17:01:58 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	locate_n(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (stacks->stack_a.list[++i] != n)
		;
	if (i <= stacks->stack_a.placed_number / 2)
		return (1);
	if (i > stacks->stack_a.placed_number / 2)
		return (2);
	return (0);
}

int	is_in_lis(int *lis, int len, int n)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (n == lis[i])
			return (1);
	}
	return (0);
}

int	is_min(int *list, int len)
{
	int	i;
	int	val;

	i = -1;
	val = list[0];
	while (++i < len)
	{
		if (list[i] < val)
			val = list[i];
	}
	return (val);
}

void	push_all_b(t_stacks *stacks)
{
	get_lis(stacks);
	while (stacks->stack_a.placed_number > stacks->lis.lis_len)
	{
		if (!is_in_lis(stacks->lis.lis, stacks->lis.lis_len,
				stacks->stack_a.list[0]))
			pb(stacks, 0, 0);
		else
			ra(stacks, 0);
	}
	while (stacks->stack_a.list[0] != is_min(stacks->stack_a.list,
			stacks->stack_a.placed_number))
		ra(stacks, 0);
	free(stacks->lis.lis);
}

int	is_not_sorted(int *list, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (list[i] > list[i + 1])
			return (1);
		i++;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;

	srand(time(NULL));
	fill_stack(&stacks, argv[1]);
	push_all_b(&stacks);
	greedy(argv[1]);
	//print_stacks(&stacks);
	free(stacks.stack_a.list);
	free(stacks.stack_b.list);
	return (0);
}
