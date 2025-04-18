/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 07:35:01 by mohel-mo          #+#    #+#             */
/*   Updated: 2025/04/18 07:35:03 by mohel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_data *data, int x, int y)
{
	static int moves;

	if (data->map->map[y][x] == '1')
		return ;
	if (data->map->map[y][x] == 'E')
	{
		if (!data->map->c)
		{
			ft_printf("Congrats! You won!");
			destroy_images(data);
		}
		else
			return ;
	}
	if (data->map->map[y][x] == 'C')
		data->map->c--;
	data->map->map[y][x] = 'P';
	data->map->map[data->map->p_y][data->map->p_x] = '0';
	data->map->p_x = x;
	data->map->p_y = y;
	moves++;
	ft_printf("%d moves so far!\n", moves);
	render_map(data);
}
