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
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

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
	int	i;

	ft_printf("{!} Map not valid!\n");
	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	exit(1);
}

void	ft_check_shape(t_map *map)
{
	int	i;
	int	len;

	map->x = ft_strlenn(map->map[0]);
	i = 0;
	len = 0;
	while (map->map[i])
	{
		len = ft_strlenn(map->map[i]);
		if (len != (map->x))
			free_wrong_shape(map);
		i++;
	}
}
