/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:54:35 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 10:57:31 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_list(t_stacks *stacks, int len)
{
	int	i;
	int	val;

	i = -1;
	val = stacks->lis.list[1][0];
	while (++i < len)
	{
		if (stacks->lis.list[0][i] > val)
		{
			val = stacks->lis.list[1][i];
			stacks->lis.index_i = i;
			stacks->lis.index_max_val = val;
		}
	}
	return (val);
}

void	increment(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (++i < stacks->stack_a.placed_number)
	{
		j = -1;
		while (++j < i)
		{
			if (stacks->lis.list[0][i] > stacks->lis.list[0][j])
			{
				if (stacks->lis.list[1][i] <= stacks->lis.list[1][j] + 1)
					stacks->lis.list[1][i] = stacks->lis.list[1][j] + 1;
			}
		}
	}
}

void	reverse(int *arr, int n)
{
	int		i;
	int		temp;

	i = -1;
	i = -1;
	while (++i < (n / 2))
	{
		temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
		i = -1;
}

void	fill_arr(t_stacks *stacks)
{
	int	arr_len;
	int	val;
	int	i;

	i = stacks->stack_a.placed_number - 1;
	arr_len = stacks->lis.list[1][stacks->lis.index_i] - 1;
	stacks->lis.lis = (int *) malloc (sizeof(int *) * arr_len);
	stacks->lis.lis[arr_len] = stacks->lis.list[0][stacks->lis.index_i];
	stacks->lis.lis_len = arr_len + 1;
	while (i > 0)
	{
		if (stacks->lis.list[0][i - 1] < stacks->lis.lis[arr_len]
				&& stacks->lis.list[1][i - 1] == arr_len)
		{
			arr_len--;
			stacks->lis.lis[arr_len] = stacks->lis.list[0][i - 1];
		}
		i--;
	}
	//reverse(stacks->lis.lis, stacks->lis.lis_len);
}

void	get_lis(t_stacks *stacks)
{
	int	i;

	i = -1;
	stacks->lis.list = (int **) malloc(sizeof(int *) * 2);
	stacks->lis.list[0] = (int *) malloc(sizeof(int)
			* stacks->stack_a.placed_number);
	stacks->lis.list[1] = (int *) malloc(sizeof(int)
			* stacks->stack_a.placed_number);
	stacks->lis.list_len = stacks->stack_a.placed_number;
	while (++i < stacks->stack_a.placed_number)
	{
		stacks->lis.list[0][i] = stacks->stack_a.list[i];
		stacks->lis.list[1][i] = 1;
	}
	increment(stacks);
	find_max_list(stacks, stacks->stack_a.placed_number);
	fill_arr(stacks);
	free(stacks->lis.list[0]);
	free(stacks->lis.list[1]);
	free(stacks->lis.list);
}