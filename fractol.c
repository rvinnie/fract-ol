#include "fractol.h"

int main()
{
	t_info 	s_info;
	t_data	img;
	void	*mlx;
	void	*win_ptr;

	s_info.w = WIDTH;
	s_info.h = HEIGHT;
	s_info.max_iter = MAX_ITER;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, s_info.w, s_info.h, "Mandelbrot set");
	img.img = mlx_new_image(mlx, s_info.w, s_info.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	s_info.img = &img;

	mandelbrot(&s_info);

	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
	mlx_loop(mlx);
	(void)win_ptr;
}

// my_pxl_put(&img, 5, 5, 0x00FF0000);
// clear_image(&s_info);

//gcc main.c ubuntu_mlx/libmlx_Linux.a  -lXext -lX11 -lm -lz