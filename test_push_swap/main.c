/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 10:56:19 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.placed_number - 1)
	{
		if (stacks->stack_a.list[i] > stacks->stack_a.list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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

void	push_all_b(t_stacks *stacks)
{
	int	i;
	int	j;
	int	n;

	while (stacks->stack_a.placed_number > 0)
	{
		get_lis(stacks);
		i = -1;
		j = 0;
		while (++i < stacks->lis.lis_len)
		{
			n = locate_n(stacks, stacks->lis.lis[j]);
			if (n == 1)
				while (stacks->stack_a.list[0] != stacks->lis.lis[j])
					ra(stacks);
			else if (n == 2)
				while (stacks->stack_a.list[0] != stacks->lis.lis[j])
					rra(stacks);
			pb(stacks, 0);
			j++;
		}
		free(stacks->lis.lis);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;

	srand(time(NULL));
	fill_stack(&stacks, argv[1]);
	push_all_b(&stacks);
	print_stacks(&stacks);
	free(stacks.stack_a.list);
	free(stacks.stack_b.list);
	return (0);
}
