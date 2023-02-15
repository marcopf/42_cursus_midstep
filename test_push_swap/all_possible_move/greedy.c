/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:41:37 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/15 22:40:33 by mpaterno         ###   ########.fr       */
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

// void	is_in_between_max(t_stacks *stacks, int *i, int *index)
// {
// 	if (is_max(stacks, stacks->stack_b.list[0]))
// 	{
// 		if (is_min_greed(stacks, stacks->stack_a.list[0]))
// 		{
// 			index = i;
// 			return () ;
// 		}
// 		while (stacks->stack_a.list[i] < stacks->stack_a.list[i + 1])
// 			i++;
// 		index = i + 1;
// 		break ;
// 	}
// 	else if (is_min_greed(stacks, stacks->stack_b.list[0]))
// 	{
// 		while (stacks->stack_a.list[i] < stacks->stack_a.list[i + 1])
// 			i++;
// 		index = i + 1;
// 		break ;
// 	}
// 	else if (stacks->stack_b.list[0] > stacks->stack_a.list[i]
// 		&& stacks->stack_b.list[0] < stacks->stack_a.list[i + 1])
// 	{
// 		index = i + 1;
// 		break ;
// 	}
// }

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
		index = (stacks->stack_a.placed_number - index) + 1000;
	return (index);
}

void	loop(t_stacks *stacks, int *arr, int *temp, int *i)
{
	while (++(*i) < stacks->stack_b.placed_number)
	{
		*temp = is_in_between(stacks) + *i;
		if (arr[0] > *temp)
		{
			arr[0] = *temp;
			arr[1] = *i;
		}
		rb(stacks, 0);
	}
	arr[0] -= arr[1];
}

int	*arr_move_maker(t_stacks *stacks)
{
	int	*arr;
	int	i;
	int	temp;

	i = -1;
	arr = (int *)malloc(sizeof(int) * 4);
	arr[0] = is_in_between(stacks);
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	loop(stacks, arr, &temp, &i);
	if (arr[0] >= 1000)
	{
		arr[0] -= 1000;
		arr[2] = 1;
	}
	if (arr[1] > (stacks->stack_b.placed_number / 2))
	{
		arr[1] = stacks->stack_b.placed_number - arr[1];
		arr[3] = 1;
	}
	return (arr);
}

void	move_combine(t_stacks *stacks, int *move)
{
	while ((move[0]) > 0 && (move[1]) > 0)
	{
		if (move[2] == 0 && move[3] == 0)
		{
			rr(stacks, 1);
			move[0]--;
			move[1]--;
		}
		else if (move[2] == 1 && move[3] == 1)
		{
			rrr(stacks, 1);
			move[0]--;
			move[1]--;
		}
		else
			break ;
	}
}

void	sort(t_stacks *stacks)
{
	int	*move;

	while (stacks->stack_b.placed_number > 0)
	{
		move = arr_move_maker(stacks);
		move_combine(stacks, move);
		if (move[2] == 1 && move[0] > 0)
			while (move[0]-- > 0)
				rra(stacks, 1);
		else
			while (move[0]-- > 0)
				ra(stacks, 1);
		if (move[3] == 1 && move[1] > 0)
			while (move[1]-- > 0)
				rrb(stacks, 1);
		else
			while (move[1]-- > 0)
				rb(stacks, 1);
		pa(stacks, 0, 1);
		free(move);
	}
}


// void	make_best_move(t_stacks *stacks)
// {
// 	int	i;
// 	int	j;
// 	int	*all_move;
// 	int	val;
// 	int	k;
// 	int	best_move[4];

// 	i = -1;
// 	while (stacks->stack_b.placed_number > 0)
// 	{
// 		all_move = arr_move_maker(stacks);
// 		best_move[0] = all_move[0];
// 		best_move[1] = 0;
// 		j = 0;
// 		while (j < stacks->stack_b.placed_number)
// 		{
// 			if (all_move[j] < best_move[0])
// 			{
// 				best_move[0] = all_move[j];
// 				best_move[1] = j;
// 			}
// 			j++;
// 		}
// 		k = -1;
// 		val = best_move[1];
// 		if (best_move[0] >= 600)
// 		{
// 			best_move[0] -= 600;
// 			while (((best_move[0]--) - best_move[1]) > 0)
// 				rra(stacks, 1);
// 			while (best_move[1]--)
// 				rb(stacks, 1);
// 			pa(stacks, 0, 1);
// 		}
// 		else
// 		{
// 			// da controllare
// 			while ((((best_move[0]--) - val) > 0) && (best_move[1]-- > 0))
// 				rr(stacks, 1);
// 			best_move[0]++;
// 			if ((best_move[0] - val) > 0)
// 			{
// 				while (((best_move[0]--) - val) > 0)
// 					ra(stacks, 1);
// 			}
// 			if ((best_move[1]) > 0)
// 			{
// 				while ((best_move[1])--)
// 					rb(stacks, 1);
// 			}
// 			pa(stacks, 0, 1);
// 		}
// 		free(all_move);
// 	}
// }

void	push_all_b_greed(t_stacks *stacks)
{
	get_lis(stacks);
	while (stacks->stack_a.placed_number > stacks->lis.lis_len)
	{
		if (!is_in_lis(stacks->lis.lis, stacks->lis.lis_len,
				stacks->stack_a.list[0]))
			pb(stacks, 0, 1);
		else
			ra(stacks, 1);
	}
	while (stacks->stack_a.list[0] != is_min(stacks->stack_a.list,
			stacks->stack_a.placed_number))
		ra(stacks, 1);
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
	sort(&stacks_cpy);
	i = -1;
	while (stacks_cpy.stack_a.list[++i] != is_min(stacks_cpy.stack_a.list,
		stacks_cpy.stack_a.placed_number))
		;
	if (i > stacks_cpy.stack_a.placed_number)
	{
		while (stacks_cpy.stack_a.list[0] != is_min(stacks_cpy.stack_a.list,
			stacks_cpy.stack_a.placed_number))
			rra(&stacks_cpy, 1);
	}
	if (i <= stacks_cpy.stack_a.placed_number)
	{
		while (stacks_cpy.stack_a.list[0] != is_min(stacks_cpy.stack_a.list,
			stacks_cpy.stack_a.placed_number))
			ra(&stacks_cpy, 1);
	}
	//print_stacks(&stacks_cpy);
	print_stacks(&stacks_cpy);
	// ft_printf("\n");
	// print_stacks(&stacks_cpy);
}
