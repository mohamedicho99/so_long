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

int	main(int argc, char **argv)
{
	t_map	map;
	char	*s;

	if (argc != 2)
	{
		ft_printf("{+} Please, provide the correct number of arguments!\n");
		exit(1);
	}
	s = argv[1];
	map = (t_map){0};
	ft_parse(&map, s);
	init_program(&map);
	return (0);
}
