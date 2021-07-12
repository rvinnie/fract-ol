#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00FFFFFF
# define COLOR_RED 0x00FF0000

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307


typedef struct s_mand
{
	double	start_a;
	double	start_b;
	double	a;
	double	b;
	double	next_a;
	double	next_b;
	double	range;
	double	hor_diff;
	double	ver_diff;
} t_mand;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_info
{
	t_data	img;
	t_mand	s_mand;
	void	*mlx;
	void	*win;
	int		kind;
	int		max_iter;
	int		w;
	int		h;
} t_info;

int		cmp_arg(char *arg);
void	print_list(void);
void	my_pxl_put(t_data *data, int x, int y, int color);
void	clear_image(t_info *s_info);
int		valid_exit(t_info *s_info);
void	mandelbrot(t_info *s_info);
int		mand_click_handler(int keycode, t_info *s_info);
int		main_drawer(t_info *s_info);
#endif
