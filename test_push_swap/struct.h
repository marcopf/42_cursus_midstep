/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:39:50 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/13 10:55:50 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct e_stack{
	int	*list;
	int	placed_number;
	int	min_num;
}	t_stack;

typedef struct e_stacks{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack middle;
	int		list_len;
}	t_stacks;
#endif
