/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:07:19 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/28 03:07:23 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_info	count_cheapest_pos(int size, t_data data)
{
	t_info	info;

	info = new_info(data, size);
	if (info.diff1 <= info.diff2 && data.pos_firs_min >= 0)
	{
		info.op_count = info.diff1;
		if (data.pos_firs_min > size / 2)
		{
			info.op_count = size - info.diff1;
			info.up = 0;
		}
	}
	else if (data.pos_last_min >= 0)
	{
		info.op_count = info.diff2;
		if (data.pos_last_min > size / 2)
		{
			info.op_count++;
			info.up = 0;
		}
	}
	if (data.pos_last_min == -1 || data.pos_firs_min == -1
		|| data.pos_last_min == data.pos_firs_min)
		info.is_empty = 1;
	return (info);
}

t_info	count_operators(t_list *stack, int max, int size)
{
	t_data	data;
	int		pos;

	data.pos_last_min = -1;
	data.pos_firs_min = -1;
	data.flag = 0;
	pos = 1;
	while (stack)
	{
		if (stack->content <= max)
		{
			if (data.flag == 0)
			{
				data.first_min = stack->content;
				data.pos_firs_min = pos;
				data.flag = 1;
			}
			data.last_min = stack->content;
			data.pos_last_min = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (count_cheapest_pos(size, data));
}

void	apply_ops(t_list *stack, t_info info)
{
	while (info.op_count--)
	{
		if (info.up == 1)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

int	find_max(t_list *stack_b, int max)
{
	int	i;

	i = 0;
	while (stack_b && stack_b->next)
	{
		if (stack_b->content == max)
		{
			return (i);
		}
		stack_b = stack_b->next;
		i++;
	}
	if (stack_b->content == max)
		return (i);
	return (-1);
}

void	find_min(t_list *stack, t_data *data)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->content < (*data).min)
		{
			(*data).min = stack->content;
			(*data).pos = i;
		}
		stack = stack->next;
		i++;
	}
}
