/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:41:48 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/14 15:58:38 by mpaterno         ###   ########.fr       */
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
void	sa(t_stacks *stacks, int flag);
void	sb(t_stacks *stacks, int flag);
void	ss(t_stacks *stacks, int flag);
void	pa(t_stacks *stacks, int k, int flag);
void	pb(t_stacks *stacks, int k, int flag);
void	ra(t_stacks *stacks, int flag);
void	rb(t_stacks *stacks, int flag);
void	rr(t_stacks *stacks, int flag);
void	rra(t_stacks *stacks, int flag);
void	rrb(t_stacks *stacks, int flag);
void	rrr(t_stacks *stacks, int flag);
int		is_min(int *list, int len);
int		is_in_lis(int *lis, int len, int n);
void	get_lis(t_stacks *stacks);
//temporary
void	print_stacks(t_stacks *stacks);
int		counter(void);
void	fill_stack_rand(t_stacks *stacks, int n);

#endif
