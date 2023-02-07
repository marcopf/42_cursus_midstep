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
	make -C ./ft_printf
	make -C ./mlx
	@cp ./mlx/libmlx.dylib .
	@cp ./ft_printf/libftprintf.a .
	$(CC) $(OBJS) -L . -lmlx -L . -lftprintf -framework OpenGL -framework AppKit -o $(NAME)

${NAME}: ${OBJS}

clean:
	make clean -C ./mlx
	make fclean -C ./ft_printf
	rm -rf libmlx.dylib
	${RM} ${OBJS}

fclean: clean
	rm libmlx.dylib libftprintf.a
	${RM} ${NAME}

re: fclean all

