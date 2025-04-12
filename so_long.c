/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 07:55:37 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/12 07:55:38 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int i = 0;
	while (map->map[i])
	{
		ft_printf("%s", map->map[i]);
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

int main(int argc, char **argv)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (argc != 2)
	{
		ft_printf("{+} Please, provide the correct number of arguments!\n");
		exit(1);
	}
	char *s = argv[1];
	ft_parse(map, s);
	//print_map(map);
	free_map(map);
	return (0);
}
