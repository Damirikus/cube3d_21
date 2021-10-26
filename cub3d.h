#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>

# define PIXEL_MAP 32

typedef struct s_xpm
{
	void	*img_ptr_xpm;
	int		width_img;
	int		height_img;
}			t_xpm;

typedef struct s_size_map
{
	int	width;
	int	height;
}		t_size_map;

typedef struct s_position_hero
{
	float		pos_hero_x;
	float		pos_hero_y;
	float		dir;
	float		start;
	float		end;
}		t_position_hero;

typedef struct s_xy
{
	int	x;
	int	y;
}		t_xy;

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

typedef struct s_data
{
	
	void			*mlx;
	void			*mlx_win;
	t_img_addr img_map;
	t_img_addr img_buffer;


	char			**map_array;
	t_position_hero *hero_position;



	t_xpm north_texture;
	t_xpm south_textur;
	t_xpm west_textur;
	t_xpm east_textur;

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
#endif