SOURCES =  ft_init_stack.c ft_check_errors.c ft_stack_utils_1.c \
		ft_sort_stacks.c ft_stack_utils_2.c ft_init_a_to_b.c \
		ft_push.c ft_swap.c ft_rotate.c ft_reverse_rotate.c \
		ft_clear_stacks.c ft_split.c push_swap.c 


BONUS_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
			push_swap_bonus.c ft_init_stack_bonus.c ft_check_errors_bonus.c \
			ft_utils_bonus.c ft_cases_bonus.c ft_push_bonus.c ft_swap_bonus.c \
			ft_rotate_bonus.c ft_rev_rotate_bonus.c ft_clear_stacks_bonus.c \
			ft_split_bonus.c

OBJS = ${SOURCES:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

NAME = push_swap
BONUS_NAME = checker
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


all: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus: ${BONUS_OBJS}
	${CC} ${CFLAGS} ${BONUS_OBJS} -o ${BONUS_NAME}

clean:
	${RM} ${OBJS}
	${RM} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re
