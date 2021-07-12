#include "fractol.h"

double	change_range(double range)
{
	double ret;

	ret = range * .2;
	return (ret);
}

int	mand_click_handler(int keycode, t_info *s_info)
{
	// printf("click - %d\n", keycode);
	if (keycode == KEY_ESC)
		valid_exit(s_info);
	else if (keycode == 122) // z
		s_info->s_mand.range -= change_range(s_info->s_mand.range);
	else if (keycode == 120) // x
		s_info->s_mand.range += change_range(s_info->s_mand.range);
	else if (keycode == KEY_UP)
		s_info->s_mand.ver_diff += change_range(s_info->s_mand.range);
	else if (keycode == KEY_DOWN)
		s_info->s_mand.ver_diff -= change_range(s_info->s_mand.range);
	else if (keycode == KEY_LEFT)
		s_info->s_mand.hor_diff += change_range(s_info->s_mand.range);
	else if (keycode == KEY_RIGHT)
		s_info->s_mand.hor_diff -= change_range(s_info->s_mand.range);
	else
		return (0);
	mandelbrot(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
	return (0);
}

void	set_info(t_info *s_info, t_mand *t_mand, int x, int y)
{
	double	x_diff;
	double	y_diff;

	x_diff = s_info->s_mand.range / (double)s_info->w;
	y_diff = s_info->s_mand.range / (double)s_info->h;
	t_mand->a = x * x_diff - s_info->s_mand.range / 2 - s_info->s_mand.hor_diff;
	t_mand->b = y * y_diff - s_info->s_mand.range / 2 - s_info->s_mand.ver_diff;
	t_mand->start_a = t_mand->a;
	t_mand->start_b = t_mand->b;
}

void 	put_set(t_info *s_info, t_mand *s_mand, int x, int y)
{
	unsigned int	color;
	int				n;

	n = 0;
	while (n < s_info->max_iter)
	{
		s_mand->next_a = s_mand->a * s_mand->a - s_mand->b * s_mand->b;
		s_mand->next_b = 2 * s_mand->a * s_mand->b;
		s_mand->a = s_mand->next_a + s_mand->start_a;
		s_mand->b = s_mand->next_b + s_mand->start_b;
		if (fabs(s_mand->a + s_mand->b) > (double)16)
			break ;
		n++;
	}
	color = n * 3 % 255;
	// if (n > 50)
	// 	color = COLOR_RED + n * 10;
	my_pxl_put(&s_info->img, x, y, color);
	if (n == s_info->max_iter)
		my_pxl_put(&s_info->img, x, y, COLOR_BLACK);
}

void	mandelbrot(t_info *s_info)
{
	int		x;
	int		y;

	y = 0;
	while (y < s_info->h)
	{
		x = 0;
		while (x < s_info->w)
		{
			set_info(s_info, &s_info->s_mand, x, y);
			put_set(s_info, &s_info->s_mand, x++, y);
		}
		y++;
	}
}
