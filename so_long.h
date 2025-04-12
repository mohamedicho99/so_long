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
} t_map;


void	ft_check_ext(const char *s);
void	ft_check_shape(t_map *map);
void	ft_isempty_map(t_map *map);
void	ft_exit(t_map *map);

#endif
