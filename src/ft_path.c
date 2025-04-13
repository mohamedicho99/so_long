/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:19:57 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/13 22:20:26 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->p_y = i;
				map->p_x = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_failed(t_map *map, char **map_copy, int i)
{
	int	j;

	ft_printf("Failed to create map copy!\n");
	j = 0;
	if (map_copy)
	{
		while (j < i)
		{
			free(map_copy[j]);
			j++;
		}
		free(map_copy);
	}
	free_map(map);
}

static void	free_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}


void	ft_validate_path(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char*) * (map->y + 1));
	if (!map_copy)
		ft_failed(map, NULL, 0);
	map_copy[map->y] = NULL;
	i = 0;
	while (i < map->y)
	{
		map_copy[i] = ft_strdup(map->map[i]);
		if (!map_copy[i])
			ft_failed(map, map_copy, i);
		i++;
	}

	free_copy(map_copy);
	find_player(map);
}