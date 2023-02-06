/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charizard_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:38 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/06 16:36:45 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_char_up(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			return ;
		else if (game->map[y - 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y - 1][x] == 'E')
			return ;
		else if (game->map[y - 1][x] == 'P')
			finish_game(game);
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'G';
	}
}

void	move_char_down(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			return ;
		else if (game->map[y + 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y + 1][x] == 'E')
			return ;
		else if (game->map[y + 1][x] == 'P')
			finish_game(game);
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'G';
	}
}

void	move_char_left(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			return ;
		else if (game->map[y][x - 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x - 1] == 'E')
			return ;
		else if (game->map[y][x - 1] == 'P')
			finish_game(game);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'G';
	}
}

void	move_char_right(t_game *game)
{
	int	x;
	int	y;

	locate_charizard(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			return ;
		else if (game->map[y][x + 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x + 1] == 'E')
			return ;
		else if (game->map[y][x + 1] == 'P')
			finish_game(game);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'G';
	}
}

int	move_charizard(t_game *game)
{
	int	random;

	if (game->frame != 29)
		return (0);
	random = rand() % 4;
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
