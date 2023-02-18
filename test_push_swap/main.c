/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 18:42:03 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ascend(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (stacks->stack_a.list[++i] != is_min(stacks->stack_a.list,
			stacks->stack_a.placed_number))
		;
	if (i > (stacks->stack_a.placed_number / 2))
	{
		while (stacks->stack_a.list[0] != is_min(stacks->stack_a.list,
				stacks->stack_a.placed_number))
			rra(stacks, 1);
	}
	if (i <= stacks->stack_a.placed_number / 2)
	{
		while (stacks->stack_a.list[0] != is_min(stacks->stack_a.list,
				stacks->stack_a.placed_number))
			ra(stacks, 1);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a.list = 0;
	stacks.stack_b.list = 0;
	if (argc < 2 || argc > 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	str_check(argv[1], &stacks);
	fill_stack(&stacks, argv[1]);
	duplicate_check(&stacks);
	if (stacks.stack_a.placed_number <= 3)
		small_sort(&stacks);
	else if (stacks.stack_a.placed_number <= 5)
		medium_sort(&stacks);
	push_all_b(&stacks);
	sort(&stacks);
	ascend(&stacks);
	free(stacks.stack_a.list);
	free(stacks.stack_b.list);
	return (0);
}
