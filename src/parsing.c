/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 07:46:53 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/12 07:47:06 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_quit_2(t_map *map)
{
	ft_printf("{-} Invalid map!\n");
	free(map);
	exit(1);
}

void	ft_count_rows(char *s, t_map *map)
{
	char *line;
	int fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		ft_quit_2(map);
	map->y = 0;
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (line == NULL)
			break;
		map->y++;
	}
	close(fd);
}

void	ft_set_values(t_map *map)
{
	map->y = 0;
	map->x = 0;
	map->p = 0;
	map->e = 0;
	map->c = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->map = NULL;
}

void	ft_alloc_rows(t_map *map, char *s)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(s, O_RDONLY);
	i = 0;
	map->map = malloc(sizeof(char*) * (map->y + 1));
	if (!map->map)
	{
		free(map);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map[i] = line;
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}


void	ft_parse(t_map *map, char *s)
{
	ft_check_ext(s);
	ft_set_values(map);
	ft_count_rows(s, map);
	ft_isempty_map(map);
	ft_alloc_rows(map, s);
	ft_check_shape(map);
	ft_valid_chars(map);
	ft_check_wall(map);
	ft_count_chars(map);
	ft_check_chars(map);
	ft_validate_path(map);
}
