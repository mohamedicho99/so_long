#include "so_long.h"
#include "gnl/get_next_line.h"

void	ft_quit_2(t_map *map)
{
	ft_printf("{+} map file not valid!");
	free(map);
	exit(1);
}

// write a function that counts the rows (done)
// write a function that sets as much of them rows to char pointers 
// write a function that 
// learn how to solve every problem from a peer of yours 
// ask ayoub to explain the whole thing with tldraw

void	ft_count_rows(char *s, t_map *map)
{
	int fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("{-} Invalid map!");
		free(map);
		exit(1);
	}
	char *line = "";

	map->y = 0;
	while (line)
	{
		line = get_next_line(fd);
		//ft_printf("%s", line);
		free(line);
		if (line == NULL)
			break;
		map->y++;
	}
	// ft_printf("re: %d\n", map->y);
	close(fd);
}

void	ft_set_values(t_map *map)
{
	map->y = 0;
	map->x = 0;
	map->map = NULL;
}

void	ft_alloc_rows(t_map *map, char *s)
{
	int fd = open(s, O_RDONLY);
	char *line;

	int i = 0;
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
	ft_check_ext(s);
	ft_set_values(map);
	ft_count_rows(s, map);
	ft_alloc_rows(map, s);
	print_map(map);
	ft_printf("rows: %d\n", map->y);

	free(map);
	return (0);
}
