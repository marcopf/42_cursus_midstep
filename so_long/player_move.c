/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:38 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/06 14:43:41 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_game *game)
{
	int	x;
	int	y;

	locate_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			game->player.collectibles--;
		else if (game->map[y - 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y - 1][x] == 'E' && game->done)
			finish_game(game);
		else if (game->map[y - 1][x] == 'G')
			finish_game(game);
		game->imgs.player = game->player.top;
		printf("moving up: %d\n", game->player.moves);
		game->player.moves++;
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
	}
}

void	move_player_down(t_game *game)
{
	int	x;
	int	y;

	locate_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			game->player.collectibles--;
		else if (game->map[y + 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y + 1][x] == 'E' && game->done)
			finish_game(game);
		else if (game->map[y + 1][x] == 'G')
			finish_game(game);
		game->imgs.player = game->player.bottom;
		printf("moving down: %d\n", game->player.moves);
		game->player.moves++;
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
	}
}

void	move_player_left(t_game *game)
{
	int	x;
	int	y;

	locate_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			game->player.collectibles--;
		else if (game->map[y][x - 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x - 1] == 'E' && game->done)
			finish_game(game);
		else if (game->map[y][x - 1] == 'G')
			finish_game(game);
		game->imgs.player = game->player.left;
		game->player.moves++;
		printf("moving left: %d\n", game->player.moves);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
	}
}

void	move_player_right(t_game *game)
{
	int	x;
	int	y;

	locate_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			game->player.collectibles--;
		else if (game->map[y][x + 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x + 1] == 'E' && game->done)
			finish_game(game);
		else if (game->map[y][x + 1] == 'G')
			finish_game(game);
		game->imgs.player = game->player.right;
		game->player.moves++;
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		printf("moving right: %d\n", game->player.moves);
	}
}

int	key_hook(int key, t_game *game)
{
	if (key == 2)
		move_player_right(game);
	else if (key == 13)
		move_player_up(game);
	else if (key == 0)
		move_player_left(game);
	else if (key == 1)
		move_player_down(game);
	else if (key == 53)
	{
		free_map(game->map);
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	if (game->player.collectibles == 0)
	{
		game->imgs.c_door = game->imgs.open_door;
		game->done = 1;
	}
	return (0);
}
