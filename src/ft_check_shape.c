/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 06:23:54 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/12 06:24:00 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_strlenn(const char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

// call it just before 
void	ft_isempty_map(t_map *map)
{
	if (map->y == 0)
	{
		ft_printf("{!} Empty map!\n");
		ft_exit(map);
	}
}

void	free_wrong_shape(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	exit(1);
}

void	ft_check_shape(t_map *map)
{
	int	i;
	int len;

	map->x = ft_strlenn(map->map[0]);
	ft_printf("re: %d\n", map->x);
	i = 0;
	len = 0;
	while (map->map[i])
	{
		len = ft_strlenn(map->map[i]);
		ft_printf("len: %d\n", len);
		if (len != (map->x))
		{
			ft_printf("{!} map not valid asat!\n");
			free_wrong_shape(map);
		}
		i++;
	}
}

// check if the map is empty or not before even doing this!
// free any pointers allocated until that point before exiting! 
