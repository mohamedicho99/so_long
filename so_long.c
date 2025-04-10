#include "so_long.h"
#include "gnl/get_next_line.h"

void	ft_quit_2(t_map *map)
{
	ft_printf("{+} map file not valid!");
	free(map);
	exit(1);
}

void	ft_fill_map(t_map *map, char *fn)
{
	int fd = open(fn, O_RDONLY);
	char *line;
	if (fd < 0)
	{
		ft_quit_2(map);
		exit(1);
	}
	map->y = 0;
	line = get_next_line(fd);
	map->x = ft_strlen(line);
	map->x--;
	while (line)
	{
		map->y++;
		line = get_next_line(fd);
	}
	ft_printf("map x: %d\n", map->x);
	ft_printf("map y: %d\n", map->y);
	free(map);
	close(fd);
}

int main(int argc, char **argv)
{
	t_map *map;

	map = malloc(sizeof(t_vars*));
	if (argc != 2)
	{
		ft_printf("{+} Please, provide the correct number of arguments!\n");
		exit(1);
	}
	char *s = argv[1];
	ft_check_ext(s);
	ft_fill_map(map, s);

	return (0);
}
