/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:34:27 by rvinnie           #+#    #+#             */
/*   Updated: 2021/08/02 16:34:28 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define JULIA "Julia set"
# define MANDELBROT "Mandelbrot set"
# define WIDTH 1000
# define HEIGHT 800
# define MAX_ITER 200

# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00FFFFFF
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

# define ZOOM_IN 5
# define ZOOM_OUT 4
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53
# define KEY_SHIFT 257
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21

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
