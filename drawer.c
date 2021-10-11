/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:33:22 by rvinnie           #+#    #+#             */
/*   Updated: 2021/08/02 16:33:23 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_keys(int keycode, t_info *s_info)
{
	if (keycode == KEY_1 || keycode == KEY_2
		|| keycode == KEY_3 || keycode == KEY_4)
	{
		s_info->s_set.range = 4;
		s_info->s_set.hor_diff = 0;
		s_info->s_set.ver_diff = 0;
	}
}

void	julia_handler(int keycode, t_info *s_info)
{
	check_keys(keycode, s_info);
	if (keycode == KEY_1)
	{
		s_info->s_set.jul_real = JUL_REAL_1;
		s_info->s_set.jul_img = JUL_IMG_1;
	}
	else if (keycode == KEY_2)
	{
		s_info->s_set.jul_real = JUL_REAL_2;
		s_info->s_set.jul_img = JUL_IMG_2;
	}
	else if (keycode == KEY_3)
	{
		s_info->s_set.jul_real = JUL_REAL_3;
		s_info->s_set.jul_img = JUL_IMG_3;
	}
	else if (keycode == KEY_4)
	{
		s_info->s_set.jul_real = JUL_REAL_4;
		s_info->s_set.jul_img = JUL_IMG_4;
	}
	else
		return ;
	draw_set(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
}

int	click_handler(int keycode, t_info *s_info)
{
	if (s_info->kind == 1)
		julia_handler(keycode, s_info);
	if (keycode == KEY_ESC)
		valid_exit(s_info);
	else if (keycode == KEY_UP)
		s_info->s_set.ver_diff += change_range(s_info->s_set.range);
	else if (keycode == KEY_DOWN)
		s_info->s_set.ver_diff -= change_range(s_info->s_set.range);
	else if (keycode == KEY_LEFT)
		s_info->s_set.hor_diff += change_range(s_info->s_set.range);
	else if (keycode == KEY_RIGHT)
		s_info->s_set.hor_diff -= change_range(s_info->s_set.range);
	else if (keycode == KEY_SHIFT)
		s_info->color = (s_info->color) % 5 + 1;
	else
		return (0);
	draw_set(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
	return (0);
}

int	mouse_wheel(int keycode, int x, int y, t_info *s_info)
{
	x = 0;
	y = 0;
	if (keycode == ZOOM_IN)
		s_info->s_set.range -= change_range(s_info->s_set.range);
	else if (keycode == ZOOM_OUT)
		s_info->s_set.range += change_range(s_info->s_set.range);
	else
		return (0);
	draw_set(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
	return (0);
}

int	main_drawer(t_info *s_info)
{
	t_data	img;
	char	*name;

	if (s_info->kind == 1)
		name = JULIA;
	else
		name = MANDELBROT;
	s_info->mlx = mlx_init();
	s_info->win = mlx_new_window(s_info->mlx, s_info->w, s_info->h, name);
	img.img = mlx_new_image(s_info->mlx, s_info->w, s_info->h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	s_info->img = img;
	sets_drawer(s_info);
	mlx_hook(s_info->win, 2, 1L << 0, click_handler, s_info);
	mlx_hook(s_info->win, 17, 1L << 0, valid_exit, s_info);
	mlx_hook(s_info->win, 4, 1L << 0, mouse_wheel, s_info);
	mlx_loop(s_info->mlx);
	return (0);
}
