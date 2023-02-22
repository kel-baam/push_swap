/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:28:17 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/19 20:28:20 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void sa(t_list *stack_a)
{
    swap(stack_a);
    write(1,"sa\n",3);
}
void sb(t_list *stack_b)
{
    swap(stack_b);
    write(1,"sb\n",3);
}

void ss(t_list *stack_a,t_list *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1,"ss\n",3);
}

void pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_b, stack_a);
    write(1,"pa\n",3);

}
void pb(t_list **stack_a,t_list **stack_b)
{
    push(stack_a,stack_b);
    write(1,"pb\n",3);
}

void ra(t_list *stack_a)
{
    rotate(stack_a);
    write(1,"ra\n",3);
}

void rb(t_list *stack_b)
{
    rotate(stack_b);
    write(1,"rb\n",3);
}

void rr(t_list *stack_a,t_list *stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1,"rr\n",3);
}

void rra(t_list *stack_a)
{
    reverse_rotate(stack_a);
    write(1,"rra\n",4);
}

void rrb(t_list *stack_b)
{
    reverse_rotate(stack_b);
    write(1,"rrb\n",4);
}

void rrr(t_list *stack_a,t_list *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1,"rrr\n",4);
}

