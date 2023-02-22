#include "push_swap.h"
unsigned int	abs_(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
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

int	*stack_to_arr(t_list *stack, int len)
{
	int	*tab;
	int	i;

	tab = malloc(len * sizeof(int));
	i = 0;
	while (stack)
	{
		tab[i] = stack->content;
		i++;
		stack = stack->next;
	}
	return (tab);
}

void	swap_arr(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void	bubbleSort(int *arr, int n)
{
	int	i,j;

	i = 0;
	//for (i = 0; i < n - 1; i++)
	while (i < n - 1)
	{
		// Last i elements are already in place
		//for (j = 0; j < n - i - 1; j++)
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_arr(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	sort_array(int *arr, int len)
{
	bubbleSort(arr, len);
}

int	*get_sorted_arry(t_list *stack)
{
	int	len;
	int	*arr;

	len = ft_lstsize(stack);
	arr = stack_to_arr(stack, len);
	sort_array(arr, len);
	return (arr);
}
