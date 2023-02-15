/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/15 13:46:15 by mpaterno         ###   ########.fr       */
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
	int	index;

	i = -1;
	while (i++ < stacks->stack_a.placed_number - 1)
	{
		if (is_max(stacks, stacks->stack_b.list[0]))
		{
			if (is_min_greed(stacks, stacks->stack_a.list[0]))
			{
				index = i;
				break ;
			}
			while (stacks->stack_a.list[i] < stacks->stack_a.list[i + 1])
				i++;
			index = i + 1;
			break ;
		}
		else if (is_min_greed(stacks, stacks->stack_b.list[0]))
		{
			while (stacks->stack_a.list[i] < stacks->stack_a.list[i + 1])
				i++;
			index = i + 1;
			break ;
		}
		else if (stacks->stack_b.list[0] > stacks->stack_a.list[i]
			&& stacks->stack_b.list[0] < stacks->stack_a.list[i + 1])
		{
			index = i + 1;
			break ;
		}
	}
	if (index > (stacks->stack_a.placed_number / 2))
		index = (stacks->stack_a.placed_number - index) + 600;
	return (index);
}

int	*arr_move_maker(t_stacks *stacks)
{
	int	*arr;
	int	i;

	i = -1;
	arr = (int *)malloc(sizeof(int) * stacks->stack_b.placed_number + 2);
	while (++i < stacks->stack_b.placed_number)
	{
		arr[i] = is_in_between(stacks) + i;
		rb(stacks, 0);
	}
	return (arr);
}

void	make_best_move(t_stacks *stacks)
{
	int	i;
	int	j;
	int	*all_move;
	int	val;
	int	k;
	int	best_move[2];

	i = -1;
	while (stacks->stack_b.placed_number > 0)
	{
		all_move = arr_move_maker(stacks);
		best_move[0] = all_move[0];
		best_move[1] = 0;
		j = 0;
		while (j < stacks->stack_b.placed_number)
		{
			if (all_move[j] < best_move[0])
			{
				best_move[0] = all_move[j];
				best_move[1] = j;
			}
			j++;
		}
		k = -1;
		val = best_move[1];
		if (best_move[0] >= 600)
		{
			best_move[0] -= 600;
			while (((best_move[0]--) - best_move[1]) > 0)
				rra(stacks, 1);
			while (best_move[1]--)
				rb(stacks, 1);
			pa(stacks, 0, 1);
		}
		else
		{
			// da controllare
			while ((((best_move[0]--) - val) > 0) && (best_move[1]-- > 0))
				rr(stacks, 1);
			best_move[0]++;
			if ((best_move[0] - val) > 0)
			{
				while (((best_move[0]--) - val) > 0)
					ra(stacks, 1);
			}
			if ((best_move[1]) > 0)
			{
				while ((best_move[1])--)
					rb(stacks, 1);
			}
			pa(stacks, 0, 1);
		}
		free(all_move);
	}
}

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
	int			*arr;
	int			i;
	int			temp;
	int			arr_move[2];

	fill_stack(&stacks_cpy, argv);
	push_all_b_greed(&stacks_cpy);
	// while (stacks_cpy.stack_b.placed_number > 0)
	// {
	// 	temp = is_in_between(&stacks_cpy);
	// 	if (temp >= 600)
	// 	{
	// 		temp -= 600;
	// 		while (temp--)
	// 			rra(&stacks_cpy, 0);
	// 		pa(&stacks_cpy, 0, 0);
	// 	}
	// 	else
	// 	{
	// 		while (temp--)
	// 			ra(&stacks_cpy, 0);
	// 		pa(&stacks_cpy, 0, 0);
	// 	}
	// }
	// while (stacks_cpy.stack_a.list[0] != is_min(stacks_cpy.stack_a.list,
	// 		stacks_cpy.stack_a.placed_number))
	// 	ra(&stacks_cpy, 0);
	//arr = arr_move_maker(&stacks_cpy);
	make_best_move(&stacks_cpy);
	i = -1;
	while (stacks_cpy.stack_a.list[0] != is_min(stacks_cpy.stack_a.list,
		stacks_cpy.stack_a.placed_number))
		ra(&stacks_cpy, 0);
	//print_stacks(&stacks_cpy);
	// ft_printf("\n");
	// print_stacks(&stacks_cpy);
}
