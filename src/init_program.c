/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 06:41:55 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/17 06:41:56 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int close_window(t_data *data)
{
	destroy_images(data);
	if (data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	normal_exit(data->map);
	return (0);
}

void	init_program(t_map *map)
{
	t_data	data;

	data.map = map;
	data.mlx = mlx_init();
	if (!data.mlx)
		close_window(&data);
	data.win = mlx_new_window(data.mlx, map->x * TILE_SIZE, map->y * TILE_SIZE, "So_Long!");
	load_textures(&data);
	render_map(&data);
	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	mlx_hook(data.win, 17, 1L<<17, close_window, &data);
	//mlx_loop_hook(data.mlx, render_map, &data);
	mlx_loop(data.mlx);
}
