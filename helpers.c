/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:29:07 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/19 20:29:09 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*pop(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack)->next)
	{
		tmp = (*stack);
		*stack = NULL;
		return (tmp);
	}
	if (stack && *stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

void	push(t_list **src_stack, t_list **dst_stack)
{
	t_list	*tmp;

	if (src_stack && *src_stack && dst_stack)
	{
		tmp = pop((src_stack));
		ft_lstadd_front(dst_stack, tmp);
	}
}

void	swap(t_list *stack)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

void	rotate(t_list *stack)
{
	int		first_content;
	t_list	*curr;

	if (stack)
	{
		first_content = stack->content;
		curr = stack;
		while (curr && curr->next)
		{
			curr->content = curr->next->content;
			curr = curr->next;
		}
		curr->content = first_content;
	}
}

void	reverse_rotate(t_list *stack)
{
	int		prev_content;
	t_list	*curr;
	int		tmp;

	if (stack)
	{
		curr = stack;
		while (curr)
		{
			tmp = curr->content;
			if (curr != stack)
				curr->content = prev_content;
			prev_content = tmp;
			curr = curr->next;
		}
		stack->content = prev_content;
	}
}
