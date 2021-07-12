#include "fractol.h"

double	change_range(double range)
{
	double ret;

	ret = range * .2;
	return (ret);
}

int	click_handler(int keycode, t_info *s_info)
{
	// printf("click - %d\n", keycode);
	if (keycode == KEY_ESC)
		valid_exit(s_info);
	else if (keycode == 122) // z
		s_info->s_set.range -= change_range(s_info->s_set.range);
	else if (keycode == 120) // x
		s_info->s_set.range += change_range(s_info->s_set.range);
	else if (keycode == KEY_UP)
		s_info->s_set.ver_diff += change_range(s_info->s_set.range);
	else if (keycode == KEY_DOWN)
		s_info->s_set.ver_diff -= change_range(s_info->s_set.range);
	else if (keycode == KEY_LEFT)
		s_info->s_set.hor_diff += change_range(s_info->s_set.range);
	else if (keycode == KEY_RIGHT)
		s_info->s_set.hor_diff -= change_range(s_info->s_set.range);
	else
		return (0);
	draw_set(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
	return (0);
}

int main_drawer(t_info *s_info)
{
	t_data	img;

	s_info->mlx = mlx_init();
	s_info->win = mlx_new_window(s_info->mlx, s_info->w, s_info->h, "Mandelbrot set");
	img.img = mlx_new_image(s_info->mlx, s_info->w, s_info->h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	s_info->img = img;
	sets_drawer(s_info);
	mlx_hook(s_info->win, 2, 1L<<0, click_handler, s_info);
	mlx_hook(s_info->win, 17, 1L<<0, valid_exit, s_info);
	mlx_loop(s_info->mlx);
	return (0);
}