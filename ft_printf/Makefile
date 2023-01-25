NAME	= libftprintf.a
HEADER	= ${NAME:.a=.h}
SRCS	= ft_printf.c hex_utils.c ptr_utils.c libft.c ft_itoa.c ft_strdup.c ft_calloc.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc ${FLAGS}
RM		= rm -f

.o:.c
	${CC} ${OBJS} $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
