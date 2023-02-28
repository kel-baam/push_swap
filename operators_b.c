/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:28:17 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/19 20:28:20 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sb(t_list *stack_b, int flag)
{
	swap(stack_b);
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	rb(t_list *stack_b, int flag)
{
	rotate(stack_b);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rrb(t_list *stack_b, int flag)
{
	reverse_rotate(stack_b);
	if (flag == 1)
		write(1, "rrb\n", 4);
}
