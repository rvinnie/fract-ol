#include "fractol.h"

int	valid_exit(t_info *s_info)
{
	mlx_destroy_image(s_info->mlx, s_info->img.img);
	mlx_destroy_window(s_info->mlx, s_info->win);
	exit(0);
	return (0);
}
