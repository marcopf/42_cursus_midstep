/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:37:39 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/12 22:17:13 by mpaterno         ###   ########.fr       */
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
	while (++i < stacks->list_len)
		ft_printf("-%d-", stacks->middle[0][i]);
	i = -1;
	ft_printf("\n\nmiddle --> ");
	while (++i < stacks->list_len)
		ft_printf("-%d-", stacks->middle[1][i]);
	ft_printf("\n");
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

void	middle_init(t_stacks *stacks)
{
	int	min;
	int	max;
	int	i;

	i = -1;
	min = find_min(stacks);
	max = find_max(stacks);
	stacks->middle = (int **) malloc(sizeof(int *) * 2);
	stacks->middle[0] = (int *) malloc(sizeof(int) * (stacks->stack_a.placed_number));
	stacks->middle[1] = (int *) malloc(sizeof(int) * (stacks->stack_a.placed_number));
	while (min <= max)
		stacks->middle[0][++i] = min++;
	i = -1;
	while (++i < stacks->stack_a.placed_number)
	{
		if (is_in_arr(stacks, stacks->middle[0][i]))
			stacks->middle[1][i] = 1;
	}
	i = 0;
	while (++i < stacks->stack_a.placed_number)
	{
			stacks->middle[1][i] += stacks->middle[1][i - 1];
	}
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
