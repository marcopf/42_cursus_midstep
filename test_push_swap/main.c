/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 12:13:59 by mpaterno         ###   ########.fr       */
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

void	bouble(t_stacks *stacks)
{
	int	i;
	int j;

	j = -1;
	i = 0;
	while (is_not_sorted(stacks->stack_b.list, stacks->stack_b.placed_number))
	{
		while (stacks->stack_b.list[0] < stacks->stack_b.list[1])
		{
			rb(stacks);
			i++;
		}
		ft_printf("%d -- %d\n\n", stacks->stack_b.list[0], stacks->stack_b.list[1]);
		sb(stacks);
		while (--i > 0)
			rrb(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;

	srand(time(NULL));
	fill_stack(&stacks, argv[1]);
	push_all_b(&stacks);
	bouble(&stacks);
	print_stacks(&stacks);
	free(stacks.stack_a.list);
	free(stacks.stack_b.list);
	return (0);
}
