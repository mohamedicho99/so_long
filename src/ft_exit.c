/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 06:49:37 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/12 06:49:44 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
			free(map->map[i]);
		free(map->map);
	}
	ft_printf("{+} Exiting program!\n");
	exit(1);
}
