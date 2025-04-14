/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:57:46 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/13 23:57:47 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_exit_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_copy[i])
	{
		j = 0;
		while (map->map_copy[i][j])
		{
			if (map->map_copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_look_for_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_copy[i])
	{
		j = 0;
		while (map->map_copy[i][j])
		{
			if (map->map_copy[i][j] == 'C')
			{
				ft_printf("{!} Invalid map... Can't reach collectible\n");
				free_copy(map->map_copy);
				free_map(map);
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_map *map, int x, int y, char t)
{
	if (x < 0 || y < 0 || x >= map->x || y >= map->y)
		return ;
	if (map->map_copy[y][x] == '1' || map->map_copy[y][x] == 'X' ||
		map->map_copy[y][x] == t)
		return ;
	map->map_copy[y][x] = 'X';
	ft_flood_fill(map, x + 1, y, t);
	ft_flood_fill(map, x - 1, y, t);
	ft_flood_fill(map, x, y - 1, t);
	ft_flood_fill(map, x, y + 1, t);
}
