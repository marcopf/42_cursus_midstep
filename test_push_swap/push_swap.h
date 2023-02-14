/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:41:48 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 09:42:08 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "struct.h"
# include <time.h>
# include "./libft/libft.h"
# include "./ft_printf/libftprintf.h"
# include "./get_next_line/get_next_line.h"
# include "stdarg.h"

void	fill_stack(t_stacks *stacks, char *str);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks, int k);
void	pb(t_stacks *stacks, int k);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	get_lis(t_stacks *stacks);
//temporary
void	print_stacks(t_stacks *stacks);
int		counter(void);
void	fill_stack_rand(t_stacks *stacks, int n);

#endif
