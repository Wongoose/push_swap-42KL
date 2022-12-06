NAME	= push_swap
CHECKER	= checker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c utils/error.c utils/validation.c utils/display.c utils/free.c utils/initialize.c \
	functions/swap.c functions/rotate.c functions/rev_rotate.c functions/push.c functions/insert.c \
	sort_small/sort_3.c sort_small/sort_5.c \
	sort_large/sort_large.c sort_large/helper_chunks.c sort_large/helper_stka.c sort_large/helper_stkb.c
SRCS_PATH	= ${addprefix src/, ${SRCS}}
OBJS		= ${SRCS_PATH:.c=.o}

CHECKER_SRCS	= src/utils/error.c src/utils/validation.c src/utils/display.c src/utils/free.c src/utils/initialize.c \
	src/functions/swap.c src/functions/rotate.c src/functions/rev_rotate.c src/functions/push.c src/checker/checker.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c
CHECKER_OBJS	= ${CHECKER_SRCS:.c=.o}

LIBFT_DIR	= libft
LIBFT_LIB	= libft.a
PRINTF_DIR	= ft_printf
PRINTF_LIB	= libftprintf.a

all: ${NAME}

${LIBFT_LIB}:
	@make bonus -C ${LIBFT_DIR}

${PRINTF_LIB}:
	@make -C ${PRINTF_DIR}

${NAME}:	${LIBFT_LIB} ${PRINTF_LIB} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_DIR}/${LIBFT_LIB} ${PRINTF_DIR}/${PRINTF_LIB} -o ${NAME}

bonus:		${LIBFT_LIB} ${PRINTF_LIB} ${CHECKER_OBJS} ${NAME}
	@${CC} ${CFLAGS} ${CHECKER_OBJS} ${LIBFT_DIR}/${LIBFT_LIB} ${PRINTF_DIR}/${PRINTF_LIB} -o ${CHECKER}

clean:
	@make clean -C ${LIBFT_DIR}
	@make clean -C ${PRINTF_DIR}
	@rm -rf ${OBJS}
	@rm -rf ${CHECKER_OBJS}

fclean: clean
	@make fclean -C ${LIBFT_DIR}
	@make fclean -C ${PRINTF_DIR}
	@rm -rf ${NAME}
	@rm -rf ${CHECKER}

re: fclean all

.PHONY:	all clean fclean re bonus