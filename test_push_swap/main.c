/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/13 12:08:49 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// int	find_min(t_stacks *stacks)
// {
// 	int	i;
// 	int	val;

// 	i = 0;
// 	val = stacks->stack_a.list[0];
// 	while (i < stacks->stack_a.placed_number)
// 	{
// 		if (stacks->stack_a.list[i] <= val)
// 			val = stacks->stack_a.list[i];
// 		i++;
// 	}
// 	stacks->stack_a.min_num = val;
// 	i = 0;
// 	val = stacks->stack_b.list[0];
// 	while (i < stacks->stack_b.placed_number)
// 	{
// 		if (stacks->stack_b.list[i] <= val)
// 			val = stacks->stack_b.list[i];
// 		i++;
// 	}
// 	stacks->stack_b.min_num = val;
// 	return (val);
// }

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

int	is_max(int n, t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_b.placed_number)
	{
		if (stacks->stack_b.list[i] > n)
			return (0);
	}
	return (1);
}

int	is_min(int n, t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_b.placed_number)
	{
		if (stacks->stack_b.list[i] < n)
			return (0);
	}
	return (4);
}

void	find_place(int n, t_stacks *stacks)
{
	int	i;

	i = -1;
	while (stacks->stack_b.list[0] < n && stacks->stack_b.list[1] > n)
		rb (stacks);
}

void	test_bouble(t_stacks *stacks)
{
	int	i;
	int	j;
	int	max;

	max = stacks->stack_a.placed_number - stacks->middle.placed_number;
	j = 0;
	i = -1;
	while (stacks->stack_a.placed_number != max)
	{
		while (stacks->stack_a.list[0] != stacks->middle.list[j])
		{
			ra(stacks);
		}
		pb(stacks, 0);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;

	fill_stack(&stacks, argv[1]);
	i = 0;
	// pb(&stacks);
	// pb(&stacks);
	// pb(&stacks);
	// pb(&stacks);
	// pb(&stacks);
	// pb(&stacks);
	// pb(&stacks);
	test_bouble(&stacks);
	print_stacks(&stacks);
	free(stacks.stack_a.list);
	free(stacks.stack_b.list);
	return (0);
}
