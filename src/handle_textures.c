/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:59:18 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/17 10:14:46 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->door)
		mlx_destroy_image(data->mlx, data->door);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	destroy_everything(data);
	normal_exit(data->map);
}

void	check_loading(t_data *data)
{
	if (!data->wall || !data->coin || !data->door || !data->player
		|| !data->floor)
		destroy_images(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == ARROW_UP)
		move_player(data, data->map->p_x, data->map->p_y - 1);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_player(data, data->map->p_x - 1, data->map->p_y);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_player(data, data->map->p_x, data->map->p_y + 1);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		move_player(data, data->map->p_x + 1, data->map->p_y);
	else if (keycode == ESC)
	{
		destroy_images(data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		normal_exit(data->map);
	}
	return (0);
}

void	load_textures(t_data *data)
{
	int	iw;
	int	ih;

	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./src/img/wall.xpm", &iw, &ih);
	data->coin = mlx_xpm_file_to_image(data->mlx,
			"./src/img/coin.xpm", &iw, &ih);
	data->door = mlx_xpm_file_to_image(data->mlx,
			"./src/img/door.xpm", &iw, &ih);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"./src/img/floor.xpm", &iw, &ih);
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./src/img/player.xpm", &iw, &ih);
	check_loading(data);
}
