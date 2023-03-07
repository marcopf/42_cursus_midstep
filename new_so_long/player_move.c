/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:38 by mpaterno          #+#    #+#             */
/*   Updated: 2023/03/07 16:59:55 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'C')
			game->player.collectibles--;
		else if (game->map[y - 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y - 1][x] == 'E' && game->done)
			win_game(game);
		else if (game->map[y - 1][x] == 'G' || game->map[y - 1][x] == 'A')
			game_over(game);
		game->imgs.player = game->player.top;
		game->player.moves++;
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		ft_printf("moving up: %d\n", game->player.moves);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.player,
			(x) * 61, ((y - 1) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		move_charizard(game);
	}
}

void	move_player_down(t_game *game, int x, int y)
{
	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'C')
			game->player.collectibles--;
		else if (game->map[y + 1][x] == 'E' && game->done == 0)
			return ;
		else if (game->map[y + 1][x] == 'E' && game->done)
			win_game(game);
		else if (game->map[y + 1][x] == 'G' || game->map[y + 1][x] == 'A')
			game_over(game);
		game->imgs.player = game->player.bottom;
		game->player.moves++;
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		ft_printf("moving down: %d\n", game->player.moves);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.player,
			(x) * 61, ((y + 1) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		move_charizard(game);
	}
}

void	move_player_left(t_game *game, int x, int y)
{
	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'C')
			game->player.collectibles--;
		else if (game->map[y][x - 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x - 1] == 'E' && game->done)
			win_game(game);
		else if (game->map[y][x - 1] == 'G' || game->map[y][x - 1] == 'A')
			game_over(game);
		game->imgs.player = game->player.left;
		game->player.moves++;
		ft_printf("moving left: %d\n", game->player.moves);
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.player,
			(x - 1) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		move_charizard(game);
	}
}

void	move_player_right(t_game *game, int x, int y)
{
	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'C')
			game->player.collectibles--;
		else if (game->map[y][x + 1] == 'E' && game->done == 0)
			return ;
		else if (game->map[y][x + 1] == 'E' && game->done)
			win_game(game);
		else if (game->map[y][x + 1] == 'G' || game->map[y][x + 1] == 'A')
			game_over(game);
		game->imgs.player = game->player.right;
		game->player.moves++;
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		ft_printf("moving right: %d\n", game->player.moves);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			(x) * 61, ((y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.player,
			(x + 1) * 61, ((y) * 61) + 30);
		move_charizard(game);
	}
}

void	*poke_catch_l(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x + 1;
	y = game->player.y;
	while (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'G')
		{
			game->map[y][x] = 'C';
			draw_map(game);
			attack_clean(game);
			break ;
		}
		if (game->map[y][x] == 'C' || game->map[y][x] == 'U')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'D';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->imgs.item, (x) * 61, ((y) * 61) + 30);
		x++;
	}
	return (0);
}

void	*poke_catch_r(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x - 1;
	y = game->player.y;
	while (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'G')
		{
			game->map[y][x] = 'C';
			draw_map(game);
			attack_clean(game);
			break ;
		}
		if (game->map[y][x] == 'C' || game->map[y][x] == 'U')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'D';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->imgs.item, (x) * 61, ((y) * 61) + 30);
		x--;
	}
	return (0);
}
void	*poke_catch_u(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y - 1;
	while (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'G')
		{
			game->map[y][x] = 'C';
			draw_map(game);
			attack_clean(game);
			break ;
		}
		if (game->map[y][x] == 'C' || game->map[y][x] == 'U')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'D';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->imgs.item, (x) * 61, ((y) * 61) + 30);
		y--;
	}
	return (0);
}
void	*poke_catch_d(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y + 1;
	while (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'E')
			break ;
		if (game->map[y][x] == 'G')
		{
			game->map[y][x] = 'C';
			draw_map(game);
			attack_clean(game);
			break ;
		}
		if (game->map[y][x] == 'C' || game->map[y][x] == 'U')
			game->map[y][x] = 'U';
		else
			game->map[y][x] = 'D';
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->imgs.item, (x) * 61, ((y) * 61) + 30);
		y++;
	}
	return (0);
}

int	key_hook(int key, t_game *game)
{
	locate_player(game);
	if (key == 2 || key == 124)
		move_player_right(game, game->player.x, game->player.y);
	else if (key == 13 || key == 126)
		move_player_up(game, game->player.x, game->player.y);
	else if (key == 0 || key == 123)
		move_player_left(game, game->player.x, game->player.y);
	else if (key == 1 || key == 125)
		move_player_down(game, game->player.x, game->player.y);
	else if (key == 34)
		poke_catch_u((void *)game);
	else if (key == 38)
		poke_catch_r(game);
	else if (key == 40)
		poke_catch_d(game);
	else if (key == 37)
		poke_catch_l(game);
	else if (key == 53)
	{
		free_map(game->map);
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	if (game->player.collectibles == 0)
		draw_exit(game);
	print_moves(game);
	return (0);
}
