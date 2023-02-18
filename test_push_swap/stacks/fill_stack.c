/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:37:39 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 20:36:36 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int	i;

	i = -1;
	printf("\n\nstack A/%d:", stacks->stack_a.placed_number);
	while (++i < stacks->stack_a.placed_number)
	{
		printf(" %d |", stacks->stack_a.list[i]);
	}
	i = -1;
	printf("\n\nstack B/%d:", stacks->stack_b.placed_number);
	while (++i < stacks->stack_b.placed_number)
	{
		printf(" %d |", stacks->stack_b.list[i]);
	}
}

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

void	fill_stack(t_stacks *stacks, char *str)
{
	char	**strs;
	int		i;
	long	val;

	i = 0;
	strs = ft_split(str, ' ');
	while (strs[i])
		i++;
	stacks->stack_a.list = (int *) malloc((sizeof(int) * i) + 1);
	stacks->stack_b.list = (int *) malloc((sizeof(int) * i) + 1);
	stacks->stack_a.placed_number = i;
	stacks->stack_b.placed_number = 0;
	stacks->list_len = i;
	i = -1;
	while (strs[++i])
	{
		val = ft_atoi(strs[i]);
		if (val > 2147483647 || val < -2147483648)
			finish(stacks);
		stacks->stack_a.list[i] = ft_atoi(strs[i]);
	}
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	push_all_b(t_stacks *stacks)
{
	while (stacks->stack_a.placed_number > 3)
		pb(stacks, 0, 1);
	small_sort_for_medium(stacks);
	ascend(stacks);
}
