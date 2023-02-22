NAME = push_swap
CC = cc
CFLAGS = #-Wall -Wextra -Werror

SUB = ft_atoi.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c push_swap.c operators.c ft_lstadd_front_bonus.c helpers.c  get_next_line.c get_next_line_utils.c error.c \
		stack.c sort_fonction.c ft_lstsize_bonus.c big_sort.c outils.c
OBJ = ${SUB:.c=.o}


all : $(NAME)

$(NAME) :
	$(CC) ${CFLAGS} ${SUB}   -o ${NAME}
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
