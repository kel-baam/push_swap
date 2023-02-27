/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:27:56 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/19 20:28:01 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack_a(char **args)
{
	t_list	*stack_a;
	int		i;
	int		my_data;

	stack_a = NULL;
	i = 1;
	while (args[i])
	{
		// CHECK IS INT
		my_data = ft_atoi(args[i]);
		ft_lstadd_back(&(stack_a), ft_lstnew(my_data));
		i++;
	}
	return (stack_a);
}

int	is_sort(t_list *stack)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	print_array(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}
