#include "push_swap.h"

void	dummy_sort(t_list **stack_a, t_list **stack_b, int pos)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 1;
	while (*stack_a)
	{
		if (i == pos)
		{
			pb(stack_a, stack_b);
			size--;
			break ;
		}
		else if (pos <= size / 2)
			ra(*stack_a);
		else
			rra(*stack_a);
	}
}


t_info	count_cheapest_pos(t_list *stack,int size, t_data *data)
{
	int	diff1;
	int	diff2;
    t_info info;

    info.is_empty=0;
    info.up=1;
    info.op_count=0;

	diff1 = abs_(data->pos_firs_min)-1;
	diff2 = abs_(size - data->pos_last_min);
	if (diff1 <= diff2 && data->pos_firs_min >=0)
    {
        info.op_count=diff1;
        if (data->pos_firs_min > size / 2)
        {
            info.up = 0;
            info.op_count++;
        }
    }
    else if(data->pos_last_min >=0)
    {
        info.op_count=diff2;
        if (data->pos_last_min > size / 2)
        {
             info.op_count++;
            info.up = 0;
        }
    }
    if (data->pos_last_min == -1 || data->pos_firs_min==-1 || data->pos_last_min ==data->pos_firs_min)
        info.is_empty=1;
    return info;
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
    return(count_cheapest_pos(stack,size,data));

}

void apply_ops(t_list *stack,t_info info)
{
    while(info.op_count--)
    {
        if(info.up==1)
            ra(stack);
        else
            rra(stack);
    }

}
void big_sort(t_list **stack_a,t_list **stack_b,int *arr)
{
    int size=ft_lstsize(*stack_a);
    t_info info;
    int max = 4;
    // apply ops on stack_a
    // printf("%d\n",info.op_count);
    while (max < size)
    {
        printf("==========%d\n",arr[max]);
        while(!(info = count_operators(*stack_a,arr[max],size)).is_empty)
        {
            apply_ops(*stack_a,info);
            // put the smallet number of stack b in top
            // push to stack B
            pb(stack_a,stack_b);
        }
        max += 5;
    }
    pb(stack_a,stack_b);

   

}
