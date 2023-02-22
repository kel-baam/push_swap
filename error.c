
#include "push_swap.h"

void print_error()
{
    write(STDERR_FILENO,MSG_ERR,ft_strlen(MSG_ERR));
    exit(1);
}