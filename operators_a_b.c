/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:12:48 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/27 12:12:51 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rrr(t_list *stack_a, t_list *stack_b,int flag)
{
	rra(stack_a,flag);
	rrb(stack_b,flag);
	if(flag==1)
		write(1, "rrr\n", 4);
}

void	ss(t_list *stack_a, t_list *stack_b,int flag)
{
	sa(stack_a,flag);
	sb(stack_b,flag);
	if(flag==1)
		write(1, "ss\n", 3);
}

void	rr(t_list *stack_a, t_list *stack_b,int flag)
{
	ra(stack_a,flag);
	rb(stack_b,flag);
	if(flag==1)
		write(1, "rr\n", 3);
}
