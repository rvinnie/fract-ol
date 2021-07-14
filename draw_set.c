#include "fractol.h"

void	my_pxl_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_info(t_info *s_info, t_set *s_set, int x, int y)
{
	double	x_diff;
	double	y_diff;

	x_diff = s_info->s_set.range / (double)s_info->w;
	y_diff = s_info->s_set.range / (double)s_info->h;
	s_set->a = x * x_diff - s_info->s_set.range / 2 - s_info->s_set.hor_diff;
	s_set->b = y * y_diff - s_info->s_set.range / 2 - s_info->s_set.ver_diff;
	s_set->start_a = s_set->a;
	s_set->start_b = s_set->b;
}

void 	put_set_pxls(t_info *s_info, t_set *s_set, int x, int y)
{
	int				n;

	n = 0;
	while (n < s_info->max_iter)
	{
		s_set->next_a = s_set->a * s_set->a - s_set->b * s_set->b;
		s_set->next_b = 2 * s_set->a * s_set->b;
		if (s_info->kind == 2)
		{
			s_set->a = s_set->next_a + s_set->start_a;
			s_set->b = s_set->next_b + s_set->start_b;
		}
		else
		{
			s_set->a = s_set->next_a + s_set->jul_real;
			s_set->b = s_set->next_b + s_set->jul_img;
		}
		if (fabs(s_set->a + s_set->b) > (double)16)
			break ;
		n++;
	}
	my_pxl_put(&s_info->img, x, y, take_color(*s_info, n));
}

void	draw_set(t_info *s_info)
{
	int		x;
	int		y;

	y = 0;
	while (y < s_info->h)
	{
		x = 0;
		while (x < s_info->w)
		{
			set_info(s_info, &s_info->s_set, x, y);
			put_set_pxls(s_info, &s_info->s_set, x++, y);
		}
		y++;
	}
}

void	sets_drawer(t_info *s_info)
{
	s_info->s_set.range = 4;
	s_info->s_set.hor_diff = 0;
	s_info->s_set.ver_diff = 0;
	if (s_info->kind == 1)
	{
		s_info->s_set.jul_real = JUL_REAL_1;
		s_info->s_set.jul_img = JUL_IMG_1;
	}
	draw_set(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
}
