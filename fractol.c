#include "fractol.h"

int	valid_exit(t_info *s_info)
{
	mlx_destroy_image(s_info->mlx, s_info->img.img);
	mlx_destroy_window(s_info->mlx, s_info->win);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	s_info;
	int		kind;

	if (argc > 1)
		kind = cmp_arg(argv[1]);
	if (argc == 1 || kind == -1)
		print_list();
	s_info.kind = kind;
	s_info.w = WIDTH;
	s_info.h = HEIGHT;
	s_info.color = 1;
	s_info.max_iter = MAX_ITER;
	main_drawer(&s_info);
	return (0);
}
