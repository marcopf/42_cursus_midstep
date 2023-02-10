/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/10 15:44:01 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stacks *stacks, char *str)
{
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(str, ' ');
	while (strs[i])
		i++;
	stacks->stack_a.list = (int *) malloc(sizeof(int) * i);
	stacks->stack_b.list = (int *) malloc(sizeof(int) * i);
	stacks->list_len = i;
	i = -1;
	while (strs[++i])
		stacks->stack_a.list[i] = ft_atoi(strs[i]);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	main(int argc, char **argv)
{	
	t_stacks	stacks;
	int			i;

	i = 0;
	fill_stack(&stacks, argv[1]);
	while (i < stacks.list_len)
		ft_printf("%d\n\n", stacks.stack_a.list[i++]);
	return (0);
}
