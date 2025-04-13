#ifndef SO_LONG_h
#define SO_LONG_h 

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"

typedef struct v_map
{
	char **map;
	int x;
	int y;
	int c;
	int e;
	int p;
	int p_x;
	int p_y;
} t_map;

void	ft_check_ext(const char *s);
void	ft_check_shape(t_map *map);
void	ft_isempty_map(t_map *map);
void	ft_exit(t_map *map);
void	ft_parse(t_map *map, char *s);
void	ft_valid_chars(t_map *map);
void	ft_check_wall(t_map *map);
void	free_map(t_map *map);
void	ft_count_chars(t_map *map);
void	ft_check_chars(t_map *map);

#endif
