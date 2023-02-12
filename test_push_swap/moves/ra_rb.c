/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:59:19 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/12 09:25:35 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ra(t_stacks *stacks)
{
	int	i;
	int	*new_arr;

	i = 0;
	if (stacks->stack_a.placed_number > 1)
	{
		new_arr = (int *) malloc(sizeof(int) * stacks->list_len);
		while (++i < stacks->stack_a.placed_number)
			new_arr[i - 1] = stacks->stack_a.list[i];
		new_arr[i - 1] = stacks->stack_a.list[0];
		free(stacks->stack_a.list);
		stacks->stack_a.list = new_arr;
	}
	ft_printf("ra\n");
	counter();
}

void	rb(t_stacks *stacks)
{
	int	i;
	int	*new_arr;

	i = 0;
	if (stacks->stack_b.placed_number > 1)
	{
		new_arr = (int *) malloc(sizeof(int) * stacks->list_len);
		while (++i < stacks->stack_b.placed_number)
			new_arr[i - 1] = stacks->stack_b.list[i];
		new_arr[i - 1] = stacks->stack_b.list[0];
		free(stacks->stack_b.list);
		stacks->stack_b.list = new_arr;
	}
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	ft_printf("rr\n");
}
