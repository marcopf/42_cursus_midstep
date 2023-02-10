NAME	= push_swap
HEADER	= ${NAME:.a=.h}
SRCS	= moves/pa_pb.c main.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc
RM		= rm -f

.o:.c
	$(CC) -Wall -Wextra -Werror -c -D BUFFER_SIZE=1 $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	cc -D BUFFER_SIZE=1 -c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
	@make -C ./libft
	@make -C ./ft_printf
	@cp ./libft/libft.a .
	@cp ./ft_printf/libftprintf.a .
	$(CC) $(OBJS) get_next_line.o get_next_line_utils.o -L . -lftprintf -L . -lft -o $(NAME)

clean:
	@make -C ./libft clean
	@make -C ./ft_printf clean
	rm -rf get_next_line.o get_next_line_utils.o
	${RM} ${OBJS}

fclean: clean
	rm -rf libft.a
	rm -rf libftprintf.a
	${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re