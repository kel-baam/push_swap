/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:13:03 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/27 12:13:05 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_two_numbers(t_list *stack_a)
{
	if (stack_a->content > stack_a->next->content)
		sa(stack_a, 1);
}

void	sort_three_numbers(t_list *stack_a)
{
	if (is_sort(stack_a))
		return ;
	if (stack_a->content > stack_a->next->content
		&& stack_a->next->content > ft_lstlast(stack_a, 0, 0)->content)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (stack_a->content > stack_a->next->content && ft_lstlast(stack_a, 0,
			0)->content < stack_a->content)
		ra(stack_a, 1);
	else if (stack_a->content > stack_a->next->content
		&& stack_a->content < ft_lstlast(stack_a, 0, 0)->content)
		sa(stack_a, 1);
	else if (stack_a->content < stack_a->next->content && ft_lstlast(stack_a, 0,
			0)->content < stack_a->content)
		rra(stack_a, 1);
	else if (stack_a->content < stack_a->next->content
		&& stack_a->content < ft_lstlast(stack_a, 0, 0)->content)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
}

void	move_small_to_b(t_list **stack_a, t_list **stack_b, t_data data,
		int size)
{
	while (*stack_a)
	{
		data.min = (*stack_a)->content;
		find_min(*stack_a, &data);
		if ((*stack_a)->content != data.min && data.pos <= size / 2)
			ra(*stack_a, 1);
		else if ((*stack_a)->content != data.min && data.pos > size / 2)
			rra(*stack_a, 1);
		else
		{
			pb(stack_a, stack_b, 1);
			size--;
			break ;
		}
	}
}

void	sort_five_numbers(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		size;
	t_data	data;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (i < 2)
	{
		find_min(*stack_a, &data);
		move_small_to_b(stack_a, stack_b, data, size);
		i++;
	}
	sort_three_numbers(*stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
