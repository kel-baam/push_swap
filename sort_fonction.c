#include "push_swap.h"



void sort_two_numbers(t_list *stack_a)
{
     if(stack_a->content>stack_a->next->content)
          sa(stack_a);
}

void sort_three_numbers(t_list *stack_a)
{

          if(is_sort(stack_a))
               return ;
          //3 2 1
          if(stack_a->content>stack_a->next->content && stack_a->next->content>ft_lstlast(stack_a,0)->content )
          {    
               sa(stack_a);
               rra(stack_a);
          }
          // 3 1 2
           else if(stack_a->content >stack_a->next->content && ft_lstlast(stack_a,0)->content<stack_a->content)
               ra(stack_a);
               // 2 1 3
          else if(stack_a->content >stack_a->next->content && stack_a->content<ft_lstlast(stack_a,0)->content)
               sa(stack_a);
               //1 3 2
          else if(stack_a->content<stack_a->next->content && ft_lstlast(stack_a,0)->content<stack_a->content)
               rra(stack_a);
          else if(stack_a->content< stack_a->next->content && stack_a->content<ft_lstlast(stack_a,0)->content )
                    {
                         rra(stack_a);
                         sa(stack_a);
                    }
   
}

void sort_five_numbers(t_list **stack_a,t_list **stack_b)
{      
     int i=0;

     int size=ft_lstsize(*stack_a);
     t_data data;

     while(i<2)
     {
       while(*stack_a)
       {
          data.min = (*stack_a)->content;
          find_min(*stack_a, &data);
          if((*stack_a)->content!= data.min && data.pos<=size/2)
                ra(*stack_a);
          else if((*stack_a)->content!= data.min && data.pos>size/2)
               rra(*stack_a);
          else 
          {
               pb(stack_a,stack_b);
               size--;
               break;
          }
       }
       i++;
     }
     sort_three_numbers(*stack_a);
     pa(stack_a,stack_b);
     pa(stack_a,stack_b);
}
