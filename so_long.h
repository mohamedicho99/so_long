#ifndef SO_LONG_h
#define SO_LONG_h 

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
#include "mlx_linux/mlx.h"

#define ESC 65307
#define TILE_SIZE 60
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define ARROW_UP 65362
#define ARROW_DOWN 65364 
#define ARROW_LEFT 65361
#define ARROW_RIGHT 65363

typedef struct v_map
{
	char **map;
	char **map_copy;
	int x;
	int y;
	int c;
	int e;
	int p;
	int p_x;
	int p_y;
} t_map;

typedef struct s_data
{
	t_map *map;
	void	*wall;
	void	*coin;
	void	*door;
	void	*floor;
	void	*player;
	void	*mlx;
	void	*win;
	char 	*addr;
}			t_data;

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
void	ft_validate_path(t_map *map);
void	ft_flood_fill(t_map *map, int x, int y, char t);
void	ft_look_for_c(t_map *map);
int		is_exit_valid(t_map *map);
void	free_copy(char **map);
void	normal_exit(t_map *map);
void	init_program(t_map *map);
void	destroy_images(t_data *data);
void	load_textures(t_data *data);
int		key_hook(int keycod, t_data *data);
int		render_map(t_data *data);
void	move_player(t_data *data, int x, int y);
void	destroy_everything(t_data *data);

#endif
