/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:59:34 by kel-baam          #+#    #+#             */
/*   Updated: 2023/10/01 12:49:01 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	int	count_min;
	int	pos;

	count_min = 0;
	while (stack_b && (*stack_b))
	{
		if ((*stack_b)->content == arr[size - 1])
			micro_x_0(stack_a, stack_b, &size);
		else if (count_min == 0 || ((*stack_b)->content > ft_lstlast(*stack_a,
					0, 0)->content))
			micro_x_1(stack_a, stack_b, &count_min);
		else
		{
			pos = find_max(*stack_b, arr[size - 1]);
			if (pos != -1)
				micro_x_2(stack_b, pos);
			else
				micro_x_3(stack_a, &count_min, &size);
		}
	}
	while (count_min--)
		rra(*stack_a, 1);
}

void	analyse_stack_b(t_list *stack_b, int size, int *arr, int index)
{
	int	first_index;
	int	last_index;
	int	middle;
	int	chunks_num;

	chunks_num = get_chunks_num(size);
	first_index = size * (index - 1) / chunks_num;
	last_index = (size * index / chunks_num);
	middle = (first_index + last_index) / 2;
	if (stack_b->content < arr[middle])
		rb(stack_b, 1);
}

void	push_back_to_b(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	while (stack_a && *stack_a)
	{
		pb(stack_a, stack_b, 1);
		if (*stack_a)
			*stack_a = (*stack_a)->next;
	}
	push_to_b(stack_a, stack_b, arr, size);
}

void	big_sort(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	int		size_tmp;
	t_info	info;
	int		index;
	int		max;

	size_tmp = size;
	index = 1;
	max = (size * index) / get_chunks_num(size);
	while (max <= size)
	{
		while (1)
		{
			info = count_operators(*stack_a, arr[max - 1], size_tmp);
			if (info.is_empty)
				break ;
			apply_ops(*stack_a, info);
			pb(stack_a, stack_b, 1);
			size_tmp--;
			analyse_stack_b(*stack_b, size, arr, index);
		}
		index++;
		max = (size * index) / get_chunks_num(size);
	}
	push_back_to_b(stack_a, stack_b, arr, size);
}
