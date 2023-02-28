/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:29:26 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/19 20:29:28 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_operator(char *buffer, t_list **stack_a, t_list **stack_b)
{
	if (!strcmp(buffer, "sa\n"))
		sa(*stack_a, 0);
	else if (!strcmp(buffer, "sb\n"))
		sb(*stack_b, 0);
	else if (!strcmp(buffer, "ss\n"))
		ss(*stack_a, *stack_b, 0);
	else if (!strcmp(buffer, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (!strcmp(buffer, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!strcmp(buffer, "ra\n"))
		ra(*stack_a, 0);
	else if (!strcmp(buffer, "rb\n"))
		rb(*stack_b, 0);
	else if (!strcmp(buffer, "rr\n"))
		rr(*stack_a, *stack_b, 0);
	else if (!strcmp(buffer, "rra\n"))
		rra(*stack_a, 0);
	else if (!strcmp(buffer, "rrb\n"))
		rrb(*stack_b, 0);
	else if (!strcmp(buffer, "rrr\n"))
		rrr(*stack_a, *stack_b, 0);
	else
		print_error();
}

void	read_apply_operators(t_list **stack_a, t_list **stack_b)
{
	char	*buffer;
	int		sort;

	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (!buffer)
			break ;
		apply_operator(buffer, stack_a, stack_b);
		free(buffer);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = init_stack_a(av);
		read_apply_operators(&stack_a, &stack_b);
		if (is_sort(stack_a) && !stack_b)
			printf("ok\n");
		else
			printf("ko\n");
	}
	return (0);
}
