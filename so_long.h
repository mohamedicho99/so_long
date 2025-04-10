#ifndef SO_LONG_h
#define SO_LONG_h 

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"

void	ft_check_ext(const char *s);

typedef struct v_map
{
	struct v_map *next;
	char *line;
	int x;
} t_map;

typedef struct map_vars
{
	int y;
	int x;
} t_vars;

#endif
