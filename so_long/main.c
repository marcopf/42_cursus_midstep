/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:41:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/06 22:59:43 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	charizard_animation(t_game *game)
{
	if (game->frame > 10)
		game->imgs.patrol = game->charizard.patrol_a;
	else
		game->imgs.patrol = game->charizard.patrol_b;
}

void	frame_setter(t_game *game)
{
	static int	frame;

	sleep(0.033);
	if (frame == 30)
		frame = 0;
	frame++;
	game->frame = frame;
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

	temp = ft_itoa(game->player.moves);
	str = ft_strjoin(ft_strdup("mosse: "), temp);
	frame_setter(game);
	charizard_animation(game);
	move_charizard(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_string_put(game->mlx, game->mlx_win, 10, 18, create_trgb(255, 255, 255, 255), str);
	draw_map(game);
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
