#____________Source Files____________#
SOURCES =  ./srcs/ft_init_stack.c ./srcs/ft_check_errors.c ./srcs/ft_stack_utils_1.c \
		./srcs/ft_sort_stacks.c ./srcs/ft_stack_utils_2.c ./srcs/ft_init_a_to_b.c \
		./srcs/ft_push.c ./srcs/ft_swap.c ./srcs/ft_rotate.c ./srcs/ft_reverse_rotate.c \
		./srcs/ft_clear_stacks.c ./srcs/ft_split.c ./srcs/push_swap.c 


#____________Bonus Files____________#
BONUS_SRCS = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
			./bonus/push_swap_bonus.c ./bonus/ft_init_stack_bonus.c ./bonus/ft_check_errors_bonus.c \
			./bonus/ft_utils_bonus.c ./bonus/ft_cases_bonus.c ./bonus/ft_push_bonus.c ./bonus/ft_swap_bonus.c \
			./bonus/ft_rotate_bonus.c ./bonus/ft_reverse_rotate_bonus.c ./bonus/ft_clear_stacks_bonus.c \
			./bonus/ft_split_bonus.c


#____________Object Files____________#
OBJS = ${SOURCES:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}


#____________Variables____________#
NAME = push_swap
BONUS_NAME = checker
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


#____________Implicit Rules____________#
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@


#____________Targets && Rules____________#
${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${BONUS_NAME}: ${BONUS_OBJS}
			${CC} ${CFLAGS} ${BONUS_OBJS} -o ${BONUS_NAME}

all: ${NAME}
	

bonus: ${BONUS_NAME}
	

clean:
	${RM} ${OBJS}
	${RM} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: ${OBJS} ${BONUS_OBJS}