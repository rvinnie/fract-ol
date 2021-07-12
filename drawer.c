#include "fractol.h"

void	julia_drawer(t_info *s_info)
{
	s_info->kind++;
	printf("julia!\n");
	exit(0);
}

void	mandelbrot_drawer(t_info *s_info)
{
	s_info->s_mand.range = 4;
	s_info->s_mand.hor_diff = 0;
	s_info->s_mand.ver_diff = 0;
	mandelbrot(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
	mlx_hook(s_info->win, 2, 1L<<0, mand_click_handler, s_info);
}

int main_drawer(t_info *s_info)
{
	t_data	img;

	s_info->mlx = mlx_init();
	s_info->win = mlx_new_window(s_info->mlx, s_info->w, s_info->h, "Mandelbrot set");
	img.img = mlx_new_image(s_info->mlx, s_info->w, s_info->h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	s_info->img = img;
	if (s_info->kind == 2)
		mandelbrot_drawer(s_info);
	else
		julia_drawer(s_info);
	mlx_hook(s_info->win, 17, 1L<<0, valid_exit, s_info);
	mlx_loop(s_info->mlx);
	return (0);
}