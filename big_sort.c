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
t_info	count_cheapest_pos(t_list *stack,int size, t_data data)
{
	int	diff1;
	int	diff2;
    t_info info;

    info.is_empty=0;
    info.up=1;
    info.op_count=0;

	diff1 = abs_(data.pos_firs_min)-1;
	diff2 = abs_(size - data.pos_last_min);
	if (diff1 <= diff2 && data.pos_firs_min >=0)
    {
        info.op_count=diff1;
        if (data.pos_firs_min > size / 2)
        {
            info.op_count = size - diff1;
            info.up = 0;
        }
    }
    else if(data.pos_last_min >=0)
    {
        info.op_count=diff2;
        if (data.pos_last_min > size / 2)
        {
            // info.op_count++;
            info.up = 0;
        }
    }
    if (data.pos_last_min == -1 || data.pos_firs_min==-1 || data.pos_last_min ==data.pos_firs_min)
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

    return(count_cheapest_pos(stack,size,*data));

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
int find_max(t_list *stack_b,int max)
{
    int i=1;

    while(stack_b && stack_b->next)
    {
        if(stack_b->content == max)
        {
            return i;
        }
        stack_b=stack_b->next;
        i++;
    
    }
    return i;

}

void final_touch(t_list **stack_a ,t_list **stack_b,int *arr,int size)
{
    while(size > 1)
    {
        int pos=find_max(*stack_b,arr[size-1]);
        t_data data;
        data.pos_firs_min = pos;
        data.pos_last_min = INT32_MAX;
        t_info info = count_cheapest_pos(*stack_b, size, data);
        // printf("%d|%d|%d|%d\n",info.op_count,pos, info.up,arr[size-1]);
        apply_ops(*stack_b, info);
        pa(stack_a, stack_b);
        size--;
    }
    pa(stack_a, stack_b);
    printf("----------------\n");
   

}

void analyse_stack_b(t_list *stack_b,int size,int *arr,int index)
{
    int first_index= size*(index-1)/5;
    int last_index=(size*index/5)-1;
    int middle=(arr[first_index]+arr[last_index])/2;
        if(stack_b->content <=middle && stack_b->next)
            rb(stack_b);
}

void big_sort(t_list **stack_a,t_list **stack_b,int *arr)
{
    int size=ft_lstsize(*stack_a);
    t_info info;
    int index=1;
    int max = 100;
    int tmp_max = max;
    // apply ops on stack_a
    while (max <= size)
    {
        while(!(info = count_operators(*stack_a,arr[max - 1],size)).is_empty)
        {
            apply_ops(*stack_a,info);
            // push to stack B
            pb(stack_a,stack_b);
             // put the smallet number of stack b in top
            analyse_stack_b(*stack_b,size,arr,index);
        }
        index++;
        max += tmp_max;
    }
    pb(stack_a,stack_b);
    //push from stack_b to stack_a
    // void final_touch(t_list *stack_a ,t_list *stack_b,int *arr,int last_index)
    final_touch(stack_a ,stack_b,arr,size);
      
}

