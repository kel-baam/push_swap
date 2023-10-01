NAME = push_swap
BONUS= checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SUB = ft_atoi.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c push_swap.c operators_a.c operators_b.c operators_a_b.c ft_lstadd_front_bonus.c helpers.c  get_next_line.c get_next_line_utils.c error.c \
		stack.c sort_fonction.c ft_lstsize_bonus.c big_sort.c utils1.c utils2.c utils3.c utils4.c ft_split.c

OBJ = ${SUB:.c=.o}

SUB_BONUS=checker.c get_next_line.c get_next_line_utils.c helpers.c operators_a.c operators_a_b.c operators_b.c ft_lstadd_back_bonus.c error.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c  stack.c ft_atoi.c ft_lstnew_bonus.c ft_split.c

OBJ_BONUS= ${SUB_BONUS:.c=.o}

all : $(NAME)

bonus : ${BONUS}

$(NAME) :$(OBJ)
	$(CC) ${CFLAGS} ${SUB} -o ${NAME}
${BONUS} :$(OBJ_BONUS)
	$(CC) ${CFLAGS} ${SUB_BONUS} -o ${BONUS}
clean :
	rm -f $(OBJ)  ${OBJ_BONUS}

fclean : clean
	rm -f $(NAME)  ${BONUS}

re : fclean all
