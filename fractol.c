#include "fractol.h"

double	change_range(double range)
{
	double ret;

	if (range)
		ret = .5;
	ret = range * .5;
// 	printf("%f\n", range);
// 	if (range > (double)1)
// 		ret = 1;
// 	else if (range <= (double)1 && fabs(range - .1) > .00000001)
// 		ret = .1;
// 	else if (fabs(range - .1) <= .0000001 && fabs(range - .01) > .00000001)
// 		ret = .01;
// 	else if (range <= .01 && range > .001)
// 		ret = .001;
// 	else if (range <= .001 && range > .0001)
// 		ret = .0001;
// 	else if (range <= .0001 && range > .00001)
// 		ret = .00001;
// 	else if (range <= .00001 && range > .000001)
// 		ret = .000001;
// 	else if (range <= .000001 && range > .0000001)
// 	{
// 		printf("!!!\n");
// 		ret = 0;
// 	}
// 	else
// 		ret = .5;
	return (ret);
}

int	click_handler(int keycode, t_info *s_info)
{
	// printf("click - %d\n", keycode);
	if (keycode == 65307)
		valid_exit(s_info);
	else if (keycode == 122) // z
		s_info->range -= change_range(s_info->range);
	else if (keycode == 120) // x
		s_info->range += change_range(s_info->range);
	else if (keycode == 65362) // up
		s_info->ver_diff += change_range(s_info->range);
	else if (keycode == 65364) // down
		s_info->ver_diff -= change_range(s_info->range);
	else if (keycode == 65361) // left
		s_info->hor_diff += change_range(s_info->range);
	else if (keycode == 65363) // right
		s_info->hor_diff -= change_range(s_info->range);

	else
		return (0);
	clear_image(s_info);
	mandelbrot(s_info);
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
	s_info->range = 4;
	s_info->hor_diff = 0;
	s_info->ver_diff = 0;
	mandelbrot(s_info);
	mlx_put_image_to_window(s_info->mlx, s_info->win, s_info->img.img, 0, 0);
	mlx_hook(s_info->win, 17, 1L<<0, valid_exit, s_info);
	mlx_hook(s_info->win, 2, 1L<<0, click_handler, s_info);
	mlx_loop(s_info->mlx);
	return (0);
}

int main(int argc, char *argv[])
{
	t_info s_info;

	if (argc == 1 || cmp_arg(argv[1]) == -1)
	{
		printf(AVAILABLE_PARAMS);
		exit(0);
	}
	s_info.w = WIDTH;
	s_info.h = HEIGHT;
	s_info.max_iter = MAX_ITER;
	main_drawer(&s_info);
	return (0);
}


// my_pxl_put(&img, 5, 5, 0x00FF0000);
// clear_image(&s_info);

//gcc main.c ubuntu_mlx/libmlx_Linux.a  -lXext -lX11 -lm -lz