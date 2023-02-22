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

void checker(char *buffer,t_list *stack_a, t_list *stack_b)
{
        if(!strcmp(buffer,"sa"))
                sa(stack_a);
        else if(!strcmp(buffer,"sb"))
                sb(stack_b);
        else if(strcmp(buffer,"ss"))
                ss(stack_a,stack_b);
        else if(strcmp(buffer,"pa"))
                pa(&stack_a,&stack_b);
        else if(strcmp(buffer,"pb"))
                pb(&stack_a,&stack_b);
        else if(strcmp(buffer,"ra"))
                ra(stack_a);
        else if(strcmp(buffer,"rb"))
                rb(stack_b);
        else if(strcmp(buffer,"rr"))
                rr(stack_a,stack_b);
        else if(strcmp(buffer,"rra"))
                rra(stack_a);
        else if(strcmp(buffer,"rrb"))
                rrb(stack_b);
        else if(strcmp(buffer,"rrr"))
                rrr(stack_a,stack_b);

}

char* read_from_stdin(t_list *stack_a,t_list *stack_b)
{
        char *buffer=NULL;
        buffer=get_next_line(1);
        while(buffer)
        {
                checker(buffer,stack_a,stack_b);
                free(buffer);
                buffer=get_next_line(1);
        }
        return NULL;
}
