/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:38:58 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/17 10:38:58 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_image(t_data *data, char c, int y, int x)
{
	if (c == '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->wall,
			TILE_SIZE * x, TILE_SIZE * y);
	}
	if (c == '0')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor,
			TILE_SIZE * x, TILE_SIZE * y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->coin,
			TILE_SIZE * x, TILE_SIZE * y);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			TILE_SIZE * x, TILE_SIZE * y);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->door,
			TILE_SIZE * x, TILE_SIZE * y);
	}
}

int	render_map(t_data *data)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	map = data->map;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			render_image(data, map->map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (0);
}
