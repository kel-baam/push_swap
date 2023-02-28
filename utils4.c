/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:07:29 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/28 03:07:33 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	micro_x_0(t_list **stack_a, t_list **stack_b, int *size)
{
	pa(stack_a, stack_b, 1);
	(*size)--;
}

void	micro_x_1(t_list **stack_a, t_list **stack_b, int *count_min)
{
	pa(stack_a, stack_b, 1);
	ra(*stack_a, 1);
	(*count_min)++;
}

void	micro_x_2(t_list **stack_b, int pos)
{
	if (pos <= ft_lstsize(*stack_b) / 2)
		rb(*stack_b, 1);
	else
		rrb(*stack_b, 1);
}

void	micro_x_3(t_list **stack_a, int *count_min, int *size)
{
	rra(*stack_a, 1);
	(*count_min)--;
	(*size)--;
}
