/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:46:51 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/12 11:14:22 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_set_value(t_map *map, char c)
{
	if (c == 'P')
		map->p++;
	else if (c == 'E')
		map->e++;
	else if (c == 'C')
		map->c++;
}

void	print_values(t_map *map)
{
	ft_printf("p: %d\n", map->p);
	ft_printf("e: %d\n", map->e);
	ft_printf("c: %d\n", map->c);
}

void	ft_count_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0; 
		while (map->map[i][j])
		{
			ft_set_value(map, map->map[i][j]);
			j++;
		}
		i++;
	}
	print_values(map);
}

void	ft_check_chars(t_map *map)
{
	if (map->p != 1)
	{
		ft_printf("{-} A single player is required!\n");
		free_map(map);
	}
	else if (map->e != 1)
	{
		ft_printf("{-} A single exit is required!\n");
		free_map(map);
	}
	else if (map->c == 0)
	{
		ft_printf("{-} At least on collectible is needed!\n");
		free_map(map);
	}
}
