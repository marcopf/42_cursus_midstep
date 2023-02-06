NAME	= so_long
HEADER	= ${NAME:.a=.h}
SRCS	= main.c map_parser.c map_check.c get_next_line.c get_next_line_utils.c draw_map.c player_func.c player_move.c game_func.c charizard_move.c
OBJS	= ${SRCS:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
FLAGS	= -Wall -Werror -Wextra
OPTIONS	= -c
CC		= gcc
RM		= rm -f

.o:.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: ${NAME}
	$(CC) $(OBJS) -L . -lmlx -framework OpenGL -framework AppKit -o $(NAME)

${NAME}: ${OBJS}

clean:
	make clean -C ./mlx
	rm -rf libmlx.dylib
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

mlx:
	make -C ./mlx
	cp ./mlx/libmlx.dylib .
