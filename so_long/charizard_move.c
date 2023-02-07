/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charizard_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:38 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/07 16:59:56 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_char_up(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			return ;
		else if (game->map[y - 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y - 1][x] == 'E')
			return ;
		else if (game->map[y - 1][x] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->charizard.patrol_b,
			(x) * 61, ((y - 1) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
	}
}

void	move_char_down(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			return ;
		else if (game->map[y + 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y + 1][x] == 'E')
			return ;
		else if (game->map[y + 1][x] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->charizard.patrol_a,
			(x) * 61, ((y + 1) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
	}
}

void	move_char_left(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			return ;
		else if (game->map[y][x - 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x - 1] == 'E')
			return ;
		else if (game->map[y][x - 1] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->charizard.patrol_b,
			(x - 1) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
	}
}

void	move_char_right(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->charizard.x;
	y = game->charizard.y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			return ;
		else if (game->map[y][x + 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x + 1] == 'E')
			return ;
		else if (game->map[y][x + 1] == 'P')
			game_over(game);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'G';
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->charizard.patrol_a,
			(x + 1) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
	}
}

int	move_charizard(t_game *game)
{
	int	random;
	static int	flag;

	if (!locate_charizard(game))
		return (0);
	if (game->frame != 15 && game->frame != 45)
		return (0);
	random = rand() % 4;
	if (flag)
	{
		game->imgs.patrol = game->charizard.patrol_a;
		flag = 1;
	}
	else
	{
		game->imgs.patrol = game->charizard.patrol_b;
		flag = 0;
	}
	if (random == 0)
		move_char_right(game);
	else if (random == 1)
		move_char_up(game);
	else if (random == 2)
		move_char_left(game);
	else if (random == 3)
		move_char_down(game);
	return (0);
}
