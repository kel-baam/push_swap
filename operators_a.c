/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:12:36 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/27 12:12:39 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_list *stack_a,int flag)
{
	swap(stack_a);
	if(flag==1)
		write(1, "sa\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b,int flag)
{
	push(stack_b, stack_a);
	if(flag==1)
		write(1, "pa\n", 3);
}

void	ra(t_list *stack_a,int flag)
{
	rotate(stack_a);
	if(flag==1)
		write(1, "ra\n", 3);
}

void	rra(t_list *stack_a,int flag)
{
	reverse_rotate(stack_a);
	if(flag==1)
		write(1, "rra\n", 4);
}


/*


	while (inst)
	{
		if (int.content== 'ra' && inst.next && int.next.conet='rb')
			print('rr)
		if int.ce
	}
*/