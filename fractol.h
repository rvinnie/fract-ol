#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define JULIA "Julia set"
# define MANDELBROT "Mandelbrot set"
# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 500

# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00FFFFFF

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define KEY_SHIFT 65505
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52

# define JUL_REAL_1 -0.70176
# define JUL_IMG_1 -0.3842
# define JUL_REAL_2 -0.8
# define JUL_IMG_2 0.156
# define JUL_REAL_3 -0.7269
# define JUL_IMG_3 0.1889
# define JUL_REAL_4 0.285
# define JUL_IMG_4 0.01

typedef struct s_set
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
	double	jul_real;
	double	jul_img;
}	t_set;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_info
{
	t_data			img;
	t_set			s_set;
	void			*mlx;
	void			*win;
	unsigned int	color;
	int				kind;
	int				max_iter;
	int				w;
	int				h;
}	t_info;

int				cmp_arg(char *arg);
void			print_list(void);
void			my_pxl_put(t_data *data, int x, int y, int color);
void			clear_image(t_info *s_info);
int				valid_exit(t_info *s_info);
void			draw_set(t_info *s_info);
int				click_handler(int keycode, t_info *s_info);
int				main_drawer(t_info *s_info);
void			sets_drawer(t_info *s_info);
unsigned int	take_color(t_info s_info, int n);
double			change_range(double range);

#endif
