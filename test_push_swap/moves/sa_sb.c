/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:45:16 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/11 18:33:34 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->stack_a.placed_number > 2)
	{
		temp = stacks->stack_a.list[0];
		stacks->stack_a.list[0] = stacks->stack_a.list[1];
		stacks->stack_a.list[1] = temp;
	}
	ft_printf("sa\n");
	counter();
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->stack_b.placed_number > 2)
	{
		temp = stacks->stack_b.list[0];
		stacks->stack_b.list[0] = stacks->stack_b.list[1];
		stacks->stack_b.list[1] = temp;
	}
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_printf("ss\n");
}
