/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:41:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/07 16:52:43 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_setter(t_game *game)
{
	static int	frame;

	if (frame == 60)
		frame = 0;
	frame++;
	game->frame = frame;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rect(int x, int y, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			my_mlx_pixel_put(&game->img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
}

void	test(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, 400, 30);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length,
								&game->img.endian);
	draw_rect(400, 30, game);
}

int	destroy(t_game *game)
{
	free_map(game->map);
	exit(0);
}

int	render(t_game *game)
{
	char	*str;
	char	*temp;

	usleep(800);
	temp = ft_itoa(game->player.moves);
	str = ft_strjoin(ft_strdup("mosse: "), temp);
	frame_setter(game);
	move_charizard(game);
	test(game);
	mlx_string_put(game->mlx, game->mlx_win, 10, 18,
		create_trgb(255, 255, 255, 255), str);
	free(temp);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		return (1);
	srand(time(NULL));
	game.mlx = mlx_init();
	game.map = map_maker(argv[1]);
	game.mlx_win = mlx_new_window(game.mlx, (ft_strlen(game.map[0]) - 1) * 62,
			((get_y(game.map)) * 62) + 10, "so_long");
	img_init(&game);
	draw_map(&game);
	mlx_hook(game.mlx_win, 2, 0, key_hook, (void *)&game);
	mlx_hook(game.mlx_win, 17, 0, destroy, (void *)&game);
	mlx_loop_hook(game.mlx, render, (void *)&game);
	mlx_loop(game.mlx);
}
