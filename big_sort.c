#include "push_swap.h"

t_info	count_cheapest_pos(t_list *stack, int size, t_data data)
{
	int		diff1;
	int		diff2;
	t_info	info;

	info.is_empty = 0;
	info.up = 1;
	info.op_count = 0;
	diff1 = abs_(data.pos_firs_min) - 1;
	diff2 = abs_(size - data.pos_last_min);
	if (diff1 <= diff2 && data.pos_firs_min >= 0)
	{
		info.op_count = diff1;
		if (data.pos_firs_min > size / 2)
		{
			info.op_count = size - diff1;
			info.up = 0;
		}
	}
	else if (data.pos_last_min >= 0)
	{
		info.op_count = diff2;
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
	t_data	*data;
	int		pos;
	int		flag;

	data = calloc(1, sizeof(t_data));
	pos = 1;
	flag = 0;
	data->pos_last_min = -1;
	data->pos_firs_min = -1;
	while (stack)
	{
		if (stack->content <= max)
		{
			if (flag == 0)
			{
				data->first_min = stack->content;
				data->pos_firs_min = pos;
				flag = 1;
			}
			data->last_min = stack->content;
			data->pos_last_min = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (count_cheapest_pos(stack, size, *data));
}

void	apply_ops(t_list *stack, t_info info)
{
	while (info.op_count--)
	{
		if (info.up == 1)
			ra(stack,1);
		else
			rra(stack,1);
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

void	push_to_b(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	int	count_min;
	int	flag;
	int	pos;

	count_min = 0;
	flag = 0;
	while (stack_b && (*stack_b))
	{
		//     printf("----------------");
		//     printf("aaa\n");
		//    // print_stack(stack_a);
		//      print_stack(*stack_a);
		//     printf("----------------");
		if ((*stack_b)->content == arr[size - 1])
		{
			pa(stack_a, stack_b,1);
			size--;
		}
		else if (count_min == 0 || ((*stack_b)->content > ft_lstlast(*stack_a,
						INT16_MAX)->content))
		{
			pa(stack_a, stack_b,1);
			ra(*stack_a,1);
			count_min++;
		}
		else
		{
			pos = find_max(*stack_b, arr[size - 1]);
			if (pos != -1)
			{
				if (pos <= ft_lstsize(*stack_b) / 2)
					rb(*stack_b,1);
				else
					rrb(*stack_b,1);
			}
			else
			{
				rra(*stack_a,1);
				count_min--;
				size--;
				;
			}
		}
	}
	while (count_min--)
	{
		rra(*stack_a,1);
	}
}
void	final_touch(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	int		pos;
		t_data data;
	t_info	info;

	while (size > 1)
	{
		pos = find_max(*stack_b, arr[size - 1]);
		data.pos_firs_min = pos;
		data.pos_last_min = INT32_MAX;
		info = count_cheapest_pos(*stack_b, size, data);
		apply_ops(*stack_b, info);
		pa(stack_a, stack_b,1);
		size--;
	}
	pa(stack_a, stack_b,1);
}
void	analyse_stack_b(t_list *stack_b, int size, int *arr, int index)
{
	int	first_index;
	int	last_index;
	int	middle;

	first_index = size * (index - 1) / 4;
	last_index = (size * index / 4);
	middle = (first_index + last_index) / 2;
	if (stack_b->content < arr[middle])
		rb(stack_b,1);
}
void	big_sort(t_list **stack_a, t_list **stack_b, int *arr)
{
	int		size;
	int		size_tmp;
	t_info	info;
	int		index;
	int		max;
	int		tmp_max;

	size = ft_lstsize(*stack_a);
	size_tmp = size;
	index = 1;
	max = (size * index) / 4;
	tmp_max = max;
	// apply ops on stack_a
	while (max <= size)
	{
		// printf("max = %d\n", max);
		while (!(info = count_operators(*stack_a, arr[max - 1],
					size_tmp)).is_empty)
		{
			apply_ops(*stack_a, info);
			// push to stack B
			pb(stack_a, stack_b,1);
			size_tmp--;
			// put the smallet number of stack b in top
			analyse_stack_b(*stack_b, size, arr, index);
		}
		index++;
		max = (size * index) / 4;
	}
	while (stack_a && *stack_a)
	{
		pb(stack_a, stack_b,1);
		if (*stack_a)
			*stack_a = (*stack_a)->next;
	}
	push_to_b(stack_a, stack_b, arr, size);
	// print_stack(*stack_a);
}
