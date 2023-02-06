/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:13:16 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/06 22:02:41 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_imgs_init(t_game *game)
{
	game->player.top = mlx_xpm_file_to_image(game->mlx, "imgs/player_top.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->player.bottom = mlx_xpm_file_to_image(game->mlx, "imgs/player_bottom.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->player.left = mlx_xpm_file_to_image(game->mlx, "imgs/player_left.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->player.right = mlx_xpm_file_to_image(game->mlx, "imgs/player_right.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.patrol_a = mlx_xpm_file_to_image(game->mlx, "imgs/charizard0.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->charizard.patrol_b = mlx_xpm_file_to_image(game->mlx, "imgs/charizard1.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
}

void	img_init(t_game *game)
{
	game->imgs.offset_x = 0;
	game->imgs.offset_y = 30;
	game->player.moves = 0;
	game->done = 0;
	collectibles_setter(game);
	player_imgs_init(game);
	game->imgs.floor = mlx_xpm_file_to_image(game->mlx, "imgs/grass.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->imgs.border = mlx_xpm_file_to_image(game->mlx, "imgs/rock.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->imgs.item = mlx_xpm_file_to_image(game->mlx, "imgs/pokeball.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->imgs.open_door = mlx_xpm_file_to_image(game->mlx, "imgs/open-door.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->imgs.c_door = mlx_xpm_file_to_image(game->mlx, "imgs/closed-door.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->imgs.player = mlx_xpm_file_to_image(game->mlx, "imgs/player_bottom.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
	game->imgs.patrol = mlx_xpm_file_to_image(game->mlx, "imgs/charizard0.xpm",
			&game->imgs.img_width, &game->imgs.img_height);
}

void	selector(t_game *game, char c)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			game->imgs.offset_x, game->imgs.offset_y);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.border,
			game->imgs.offset_x, game->imgs.offset_y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.c_door,
			game->imgs.offset_x, game->imgs.offset_y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			game->imgs.offset_x, game->imgs.offset_y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.item,
			game->imgs.offset_x, game->imgs.offset_y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			game->imgs.offset_x, game->imgs.offset_y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.player,
			game->imgs.offset_x, game->imgs.offset_y);
	}
	else if (c == 'G')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.floor,
			game->imgs.offset_x, game->imgs.offset_y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.patrol,
			game->imgs.offset_x, game->imgs.offset_y);
	}
}

void	draw_map(t_game *game)
{
	int		i;
	size_t	j;

	i = -1;
	game->imgs.offset_x = 0;
	game->imgs.offset_y = 30;
	while (++i < get_y(game->map))
	{
		j = -1;
		while (++j < ft_strlen(game->map[0]))
		{
			selector(game, game->map[i][j]);
			game->imgs.offset_x += 61;
		}
		game->imgs.offset_x = 0;
		game->imgs.offset_y += 61;
	}
}
