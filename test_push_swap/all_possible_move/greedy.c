/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 17:16:16 by mpaterno         ###   ########.fr       */
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

int	is_in_between(t_stacks *stacks)
{
	int	i;
	int	index;

	i = -1;
	while (i++ < stacks->stack_a.placed_number - 1)
	{
		if (is_max(stacks, stacks->stack_b.list[0]))
		{
			while (stacks->stack_a.list[i] < stacks->stack_a.list[i + 1])
				i++;
			ft_printf("\n\n:%d:\n\n", i);
			index = i - 1;
			break ;
		}
		else if (stacks->stack_b.list[0] > stacks->stack_a.list[i]
			&& stacks->stack_b.list[0] < stacks->stack_a.list[i + 1])
			index = i;
	}
	if (index > (stacks->stack_a.placed_number / 2))
		return (599 + (stacks->stack_a.placed_number - index));
	else
		return (index + 2);
	return (-1);
}

// int	place_it(t_stacks *stacks, int n)
// {
// 	int	i;

// 	i = 0;
// 	while(1)
// 	{
// 		if (stacks->stack_a.list[0] > n)
// 			pa(stacks, 0);
// 		while ()
// 		if (n > stacks->stack_a.list[i] && n < stacks->stack_a[i + 1])
// 	}
// }

void	push_all_b_greed(t_stacks *stacks)
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

void	greedy(char *argv)
{
	t_stacks	stacks_cpy;
	int temp;

	fill_stack(&stacks_cpy, argv);
	push_all_b_greed(&stacks_cpy);
	temp = is_in_between(&stacks_cpy);
	ft_printf("||%d||\n\n", temp);
	if (temp >= 600)
	{
		temp -= 600;
		while (temp--)
			rra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
	else
	{
		while (temp--)
			ra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
	print_stacks(&stacks_cpy);
		temp = is_in_between(&stacks_cpy);
		ft_printf("||%d||\n\n", temp);
	if (temp >= 600)
	{
		temp -= 600;
		while (temp--)
			rra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
	else
	{
		while (temp--)
			ra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
	print_stacks(&stacks_cpy);
			temp = is_in_between(&stacks_cpy);
		ft_printf("||%d||\n\n", temp);
	if (temp >= 600)
	{
		temp -= 600;
		while (temp--)
			rra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
	else
	{
		while (temp--)
			ra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
				temp = is_in_between(&stacks_cpy);
		ft_printf("||%d||\n\n", temp);
	if (temp >= 600)
	{
		temp -= 600;
		while (temp--)
			rra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
	else
	{
		while (temp--)
			ra(&stacks_cpy, 0);
		pa(&stacks_cpy, 0, 0);
	}
	print_stacks(&stacks_cpy);
	ft_printf("!!%d!!", is_in_between(&stacks_cpy));
	ft_printf("<<%d>>\n\n", stacks_cpy.stack_a.placed_number);
}
