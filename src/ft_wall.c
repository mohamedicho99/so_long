/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:47:24 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/12 08:47:25 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_check_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_wall(t_map *map)
{
	int	i;

	i = 0;
	if (!ft_check_line(map->map[0]) || !ft_check_line(map->map[map->y - 1]))
	{
		ft_printf("{-} Invalid map: wall problems!\n");
		free_map(map);
	}
	while (map->map[i])
	{
		if (map->map[i][0] != '1' || map->map[i][map->x - 1] != '1')
		{
			ft_printf("{-} Invalid map: wall problems!\n");
			free_map(map);
		}
		i++;
	}
}
