#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# define PIXEL_MAP 16
# define PIXEL_WIDTH 1280
# define PIXEL_HEIGHT 640
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.06
# define TEX_WIDTH 128
# define TEX_HEIGHT 128

typedef struct s_xpm
{
	void	*img_ptr_xpm;
	int		width_img;
	int		height_img;
	char 	*path;
}			t_xpm;

typedef struct s_size_map
{
	int	width;
	int	height;
}		t_size_map;

typedef struct s_xy
{
	double	pos_x;
	double	pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double time; // время текущего кадра
	double oldTime; // время предыдущего кадра
}		t_xy;

//typedef struct s_raycasting
//{
//	double camera_x;
//	double raydir_x;
//	double raydir_y;
//	int map_x;
//	int map_y;
//} t_raycasting;

typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;

typedef struct s_img_addr
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;	
} t_img_addr;

typedef struct s_arrays
{
	int **color_north;
	int **color_south;
	int **color_west;
	int **color_east;

}t_arrays;

typedef struct s_data
{
	
	void			*mlx;
	void			*mlx_win;
	t_img_addr img_map;
	t_img_addr img_buffer;

	int **map_array_int;
	char **full_array;
	char **map_array;
	t_xy start_position_int;
	t_size_map size_map;

	t_arrays *arrays_for_color;

	t_xpm north_texture;
	t_xpm south_texture;
	t_xpm west_texture;
	t_xpm east_texture;

	t_color floor;
	t_color ceiling;

}					t_data;


t_data *ft_init(int argc, char **argv);
char	**init_map_array(char *filename, t_data *main);
int	ft_qw_line(int fd);
int	ft_mlx_close(t_data *data);
void my_mlx_pixel_put(t_img_addr *img, int x, int y, int color);
void ft_start_game(t_data *data);
int ft_game(t_data *data);
int ft_rgb_handler(int r, int g, int b);
void cut_array(t_data *data);
int ft_draw_map(t_data *data);
void init_int_array(t_data *data);
int ft_key_handler(int key, t_data *data);
#endif