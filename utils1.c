/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:19:00 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/27 12:19:04 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
void	bubblesort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
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
	bubblesort(arr, len);
}

int	*get_sorted_arry(t_list *stack, int len)
{
	int	*arr;

	arr = stack_to_arr(stack, len);
	sort_array(arr, len);
	return (arr);
}
