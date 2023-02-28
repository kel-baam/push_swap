/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-baam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:25:42 by kel-baam          #+#    #+#             */
/*   Updated: 2023/02/27 12:25:45 by kel-baam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define MSG_ERR "Error\n"
# define BIG_CHUNKS 4
# define SMALL_CHUNKS 5

typedef struct s_list
{
	struct s_list	*next;
	int				content;
}					t_list;
typedef struct s_data
{
	int				min;
	int				flag;
	int				pos;
	int				first_min;
	int				pos_firs_min;
	int				last_min;
	int				pos_last_min;
}					t_data;
typedef struct s_info
{
	int				op_count;
	int				up;
	int				is_empty;
	int				diff1;
	int				diff2;
	int				max;
	int				chunks_num;
}					t_info;
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
int					ft_index_newline(char *buff);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_next_line(int fd);
int					ft_atoi(char *str);
t_list				*ft_lstlast(t_list *lst, int new_val, int flag);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				push(t_list **src_stack, t_list **dst_stack);
void				swap(t_list *stack);
void				rotate(t_list *stack);
void				reverse_rotate(t_list *stack);
void				print_error(void);
void				check_data(char **args);
t_list				*init_stack_a(char **args, int *len);
int					is_sort(t_list *stack);
void				sa(t_list *stack_a, int flag);
void				sb(t_list *stack_b, int flag);
void				ss(t_list *stack_a, t_list *stack_b, int flag);
void				pa(t_list **stack_a, t_list **stack_b, int flag);
void				pb(t_list **stack_a, t_list **stack_b, int flag);
void				ra(t_list *stack_a, int flag);
void				rb(t_list *stack_b, int flag);
void				rr(t_list *stack_a, t_list *stack_b, int flag);
void				rra(t_list *stack_a, int flag);
void				rrb(t_list *stack_b, int flag);
void				rrr(t_list *stack_a, t_list *stack_b, int flag);
void				sort_two_numbers(t_list *stack_a);
void				sort_three_numbers(t_list *stack_a);
void				sort_five_numbers(t_list **stack_a, t_list **stack_b);
void				dummy_sort(t_list **stack_a, t_list **stack_b, int pos);
void				find_min(t_list *stack, t_data *data);
int					ft_lstsize(t_list *lst);
void				print_stack(t_list *stack);
int					*get_sorted_arry(t_list *stack, int len);
int					*stack_to_arr(t_list *stack, int len);
t_info				count_operators(t_list *stack, int max, int size);
void				print_array(int *arr, int len);
unsigned int		abs_(int num);
void				big_sort(t_list **stack_a, t_list **stack_b, int *arr,
						int size);
t_info				new_info(t_data data, int size);
int					get_chunks_num(int size);
char				**ft_split(char const *s, char c);
int					find_max(t_list *stack_b, int max);
void				apply_ops(t_list *stack, t_info info);
void				micro_x_0(t_list **stack_a, t_list **stack_b, int *size);
void				micro_x_1(t_list **stack_a, t_list **stack_b,
						int *count_min);
void				micro_x_2(t_list **stack_b, int pos);
void				micro_x_3(t_list **stack_a, int *count_min, int *size);

#endif
