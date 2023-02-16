/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:37:39 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/16 14:46:04 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stacks(t_stacks *stacks)
// {
// 	int	i;

// 	i = -1;
// 	ft_printf("\n\nA|%d --> ", stacks->stack_a.placed_number);
// 	ft_printf("/");
// 	while (++i < stacks->stack_a.placed_number)
// 		ft_printf("%d/ /", stacks->stack_a.list[i]);
// 	i = -1;
// 	ft_printf("\n\nB|%d --> ", stacks->stack_b.placed_number);
// 	ft_printf("/");
// 	while (++i < stacks->stack_b.placed_number)
// 		ft_printf("%d/ /", stacks->stack_b.list[i]);
// 	ft_printf("\n\n\n");
// }

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
	free(strs);
}

int	is_in_lis(int *lis, int len, int n)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (n == lis[i])
			return (1);
	}
	return (0);
}

int	is_not_in_list(int *list, int len, int n)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (n == list[i])
			return (1);
	}
	return (0);
}
