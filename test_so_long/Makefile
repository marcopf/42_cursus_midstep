NAME	= so_long
HEADER	= ${NAME:.a=.h}
SRCS	= main.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc ${FLAGS}
RM		= rm -f

.o:.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: ${NAME}
	$(CC) $(OBJS) -L . -lmlx -framework OpenGL -framework AppKit -o $(NAME)

${NAME}: ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all