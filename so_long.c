#include "so_long.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void	ft_quit_2(t_vars *map)
{
	ft_printf("{+} map file not valid!");
	free(map);
	exit(1);
}

void	ft_fill_map(t_vars *map, char *fn)
{
	int fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		ft_quit_2(map);
		exit(1);
	}
	ft_printf("re: %d\n", fd);
	map->x = 1;
	free(map);
}

int main(int argc, char **argv)
{
	t_vars *map_vars;

	map_vars = malloc(sizeof(t_vars*));
	if (argc != 2)
	{
		ft_printf("{+} Please, provide the correct number of arguments!\n");
		exit(1);
	}
	char *s = argv[1];
	ft_check_ext(s);
	ft_fill_map(map_vars, s);

	return (0);
}
