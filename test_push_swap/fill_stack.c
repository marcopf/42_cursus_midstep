/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:37:39 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/13 13:00:21 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int	i;

	i = -1;
	ft_printf("\n\nA/%d --> ", stacks->stack_a.placed_number);
	while (++i < stacks->stack_a.placed_number)
		ft_printf("-%d-", stacks->stack_a.list[i]);
	i = -1;
	ft_printf("\n\nB/%d --> ", stacks->stack_b.placed_number);
	while (++i < stacks->stack_b.placed_number)
		ft_printf("-%d-", stacks->stack_b.list[i]);
	i = -1;
	ft_printf("\n\nmiddle --> ");
	while (++i < stacks->middle.placed_number)
		ft_printf("-%d-", stacks->middle.list[i]);
	i = -1;
}

int	find_min(t_stacks *stacks)
{
	int	i;
	int	val;

	i = -1;
	val = stacks->stack_a.list[0];
	while (++i < stacks->stack_a.placed_number)
	{
		if (stacks->stack_a.list[i] < val)
			val = stacks->stack_a.list[i];
	}
	return (val);
}

int	find_max(t_stacks *stacks)
{
	int	i;
	int	val;

	i = -1;
	val = stacks->stack_a.list[0];
	while (++i < stacks->stack_a.placed_number)
	{
		if (stacks->stack_a.list[i] > val)
			val = stacks->stack_a.list[i];
	}
	return (val);
}

int	is_in_arr(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (++i < stacks->stack_a.placed_number)
	{
		if (stacks->stack_a.list[i] == n)
			return (1);
	}
	return (0);
}

int	find_max_list(int *list, int len)
{
	int	i;
	int	val;

	i = -1;
	val = list[0];
	while (++i < len)
	{
		if (list[i] > val)
			val = list[i];
	}
	return (val);
}

void	middle_init(t_stacks *stacks)
{
	int	count;
	int	*arr;
	int	j;
	int	i;
	int	val;

	i = -1;
	stacks->middle.list = (int *) malloc(sizeof(int)
			* (stacks->stack_a.placed_number));
	arr = (int *) malloc(sizeof(int)
			* (stacks->stack_a.placed_number));
	count = -1;
	while (++count < stacks->stack_a.placed_number)
	{
		j = -1;
		val = stacks->stack_a.list[count];
		while (++i < stacks->stack_a.placed_number)
		{
			if (stacks->stack_a.list[i] >= val)
			{
				val = stacks->stack_a.list[i];
				stacks->middle.list[++j] = val;
				stacks->middle.placed_number = j + 1;
			}	
		}
		arr[count] = j + 1;
		i = count;
	}
	i = -1;
	val = 0;
	// while (++i < stacks->stack_a.placed_number)
	// {
	// 	if (arr[i] > val)
	// 		val = arr[i];
	// 	if (val == find_max_list(arr, stacks->stack_a.placed_number))
	// 	{
	// 		j = -1;
	// 		val = stacks->stack_a.list[i];
	// 		while (++i < stacks->stack_a.placed_number)
	// 		{
	// 			if (stacks->stack_a.list[i] >= val)
	// 			{
	// 				val = stacks->stack_a.list[i];
	// 				stacks->middle.list[++j] = val;
	// 				stacks->middle.placed_number = j + 1;
	// 			}
	// 		}
	// 		return ;
	// 	}
	// }
	ft_printf("\n");
}

void	fill_stack(t_stacks *stacks, char *str)
{
	char	**strs;
	int		i;

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
		stacks->stack_a.list[i] = ft_atoi(strs[i]);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	middle_init(stacks);
	free(strs);
}
