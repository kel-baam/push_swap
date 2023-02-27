/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:27:35 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/19 20:27:39 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	my_sort(t_list **stack_a, t_list **stack_b, int size, int *arr)
{
	if (!is_sort(*stack_a))
	{
		if (size == 2)
			sort_two_numbers(*stack_a);
		else if (size == 3)
			sort_three_numbers(*stack_a);
		else if (size == 5 || size == 4)
			sort_five_numbers(stack_a, stack_b);
		else
			big_sort(stack_a, stack_b, arr);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		sort;
	int		*arr;

	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = init_stack_a(av);
		arr = get_sorted_arry(stack_a);
		my_sort(&stack_a, &stack_b, ac - 1, arr);
		sort = is_sort(stack_a);
		if (sort)
			printf("sorted!\n");
		else
			printf("not sorted!\n");
	}
	return (0);
}
