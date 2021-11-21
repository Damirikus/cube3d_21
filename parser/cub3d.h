#ifndef CUB3D_H
# define CUB3D_H
# define PIXEL_MAP 16
# define PIXEL_WIDTH 1920
# define PIXEL_HEIGHT 1080
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.06
# define TEX_WIDTH 128
# define TEX_HEIGHT 128

#include "libft/libft.h"
#include "GNL/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

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
	t_list			*list;
	int 			maplines;
	int				strlen_up;
	int				strlen_bot;
	int				map_str_len;
	int player;
	int				n;
	int flag;
	char			**map;
	int 	color_flag;
	int 	close_flag;
	
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



int			valid_map(char **map, int i, int j, t_data *d);
int			main(int argc, char **argv);
void		check_type(char *argv);
int			parser(int argc, char **argv, t_data *d);
int			confirm_pars(t_data *d);
int			parsing_gnl_line(t_data *d, char *line);
int			parsing_path(t_data *d, char *line);
int			list_to_map(int argc, t_data *d);
int			check_path(char *path, t_xpm *x, t_data *d);
int			check_color(char *line, t_color *c, t_data *d);
int			ft_str_empty(const char *line);
int			ft_empt(const char c);
int			map_error(int code);


#endif