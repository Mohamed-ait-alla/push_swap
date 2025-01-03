SRCS =  ft_init_stack.c ft_check_errors.c ft_utils.c \
		ft_sort_stacks.c ft_stack_utils.c ft_init_a_to_b.c \
		ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c \
		ft_clear_stacks.c ft_split.c push_swap.c 

OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
