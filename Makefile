NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c utils/error.c utils/validation.c utils/display.c utils/free.c \
	functions/swap.c functions/rotate.c functions/rev_rotate.c functions/push.c functions/insert.c\
	sort_small/sort_3.c sort_small/sort_5.c \
	sort_large/sort_large.c sort_large/helper_chunks.c sort_large/helper_stka.c sort_large/helper_stkb.c
SRCS_P	= ${addprefix src/, ${SRCS}}
OBJS	= ${SRCS_P:.c=.o}

LIBFT_DIR	= libft
LIBFT_LIB	= libft.a

all:	${NAME}

${LIBFT_LIB}:
	@make bonus -C ${LIBFT_DIR}

${NAME}:	${LIBFT_LIB} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_DIR}/${LIBFT_LIB} -o ${NAME}

clean:
	@make clean -C ${LIBFT_DIR}
	@rm -rf ${OBJS}

fclean: clean
	@make fclean -C ${LIBFT_DIR}
	@rm -rf ${NAME}

re: fclean all

.PHONY:	all clean fclean re