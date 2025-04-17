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

static void	print_map(t_map *map)
{
	int i = 0;
	ft_printf("original: \n");
	while (map->map[i])
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
}

// void	init_program(t_map *map)
// {
// 	t_data	data;
// 	char	*rel_path = "./src/img/wall.xpm";
// 	int		img_height;
// 	int		img_width;
//
// 	data.map = map;
// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx, 600, 500, "hello world!");
// 	data.img = mlx_xpm_file_to_image(data.mlx, rel_path, &img_width, &img_height);
// 	if (!data.img)
// 		ft_printf("{-} this is not working asat...\n");
// 	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
// 	mlx_put_image_to_window(data.mlx, data.win, data.img, 50, 50);
// 	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
// 	mlx_hook(data.win, 17, 1L<<17, close_window, &data);
// 	mlx_loop(data.mlx);
// }

int main(int argc, char **argv)
{
	t_map	*map;
	char	*s;

	if (argc != 2)
	{
		ft_printf("{+} Please, provide the correct number of arguments!\n");
		exit(1);
	}
	map = malloc(sizeof(t_map));
	s = argv[1];
	ft_parse(map, s);
	ft_printf("\n");
	print_map(map);
	ft_printf("\n");
	init_program(map);
	normal_exit(map);
	return (0);
}
