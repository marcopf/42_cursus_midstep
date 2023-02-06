/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:13:30 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/06 14:02:00 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_set(char c)
{
	char	*set;
	int		i;

	set = "01CEPG";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_rect(char **map)
{
	size_t	i;
	size_t	x;
	size_t	y;

	y = get_y(map);
	x = ft_strlen(map[0]);
	i = 0;
	if (x - 1 == y)
		return (0);
	while (i < y)
	{
		if (!(ft_strlen(map[i]) == x))
			break ;
		i++;
	}
	if (i == y)
		return (1);
	return (0);
}

int	border_wall(char **map)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(map[0]);
	while (map[0][i] != '\n')
	{
		if (map[0][i++] != '1')
			return (0);
	}
	i = 0;
	while ((map[get_y(map) - 1][i] != '\n'))
	{
		if (map[get_y(map) - 1][i++] != '1')
			return (0);
	}
	i = 0;
	while (map[i])
	{
		if ((map[i][0] != '1') || (map[i][k - 2] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	can_we_get_out(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'E')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_map(char **map)
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (!is_in_set(map[i][j]))
				return (0);
				j++;
		}
		i++;
	}
	if (!border_wall(map) || !is_rect(map) || !can_we_get_out(map))
		return (0);
	else
		return (1);
}
