/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:41:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/05 21:36:31 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	draw_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		return (1);
	game.mlx = mlx_init();
	game.map = map_maker(argv[1]);
	game.mlx_win = mlx_new_window(game.mlx, (ft_strlen(game.map[0]) - 1) * 62,
			(get_y(game.map)) * 62, "Hello world!");
	img_init(&game);
	draw_map(&game);
	mlx_hook(game.mlx_win, 2, 0, key_hook, (void *)&game);
	mlx_loop_hook(game.mlx, render, (void *)&game);
	mlx_loop(game.mlx);
}
