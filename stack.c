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

t_list	*init_stack_a(char **args, int *len)
{
	t_list	*stack_a;
	int		i;
	int		my_data;
	char	**numbers;
	char	**tmp;

	stack_a = NULL;
	i = 1;
	while (args[i])
	{
		numbers = ft_split(args[i], ' ');
		tmp = numbers;
		while (tmp && *tmp)
		{
			my_data = ft_atoi(*tmp);
			ft_lstadd_back(&(stack_a), ft_lstnew(my_data));
			free(*tmp);
			tmp++;
			*len = *len + 1;
		}
		free(numbers);
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
