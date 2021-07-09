#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00FFFFFF
# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_mand
{
	double	start_a;
	double	start_b;
	double	a;
	double	b;
	double	next_a;
	double	next_b;
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
	int		w;
	int		h;
	int		max_iter;
	t_data	*img;
} t_info;

void	my_pxl_put(t_data *data, int x, int y, int color);
void	clear_image(t_info *s_info);
void	mandelbrot(t_info *s_info);


#endif
