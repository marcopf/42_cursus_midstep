/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:57:41 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/18 20:50:48 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a.list = 0;
	stacks.stack_b.list = 0;
	if (argc < 2 || argc > 2)
		return (0);
	str_check(argv[1], &stacks);
	fill_stack(&stacks, argv[1]);
	if (is_sorted(&stacks))
		finish_no_e(&stacks);
	duplicate_check(&stacks);
	if (stacks.stack_a.placed_number <= 3)
		small_sort(&stacks);
	push_all_b(&stacks);
	sort(&stacks);
	ascend(&stacks);
	finish_no_e(&stacks);
	return (0);
}
