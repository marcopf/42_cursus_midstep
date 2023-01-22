NAME	= libftprintf.a
HEADER	= ${NAME:.a=.h}
SRCS	= ft_printf.c hex_utils.c mini_libft.c printf_utils.c ptr_utils.c write_utils.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc ${FLAGS}
RM		= rm -f

.o:.c
	${CC} ${OBJS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
