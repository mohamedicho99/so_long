/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_resources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:03:04 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/12 08:03:06 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_is_valid(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E' || c == '\n')
		return (1);
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	exit(1);
}

void	ft_valid_chars(t_map *map)
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
			if (!ft_is_valid(map->map[i][j]))
			{
				ft_printf("{-} Map isn't valid\n");
				free_map(map);
			}
			j++;
		}
		i++;
	}
}
