#include "fractol.h"

int main(int argc, char *argv[])
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
	s_info.max_iter = MAX_ITER;
	main_drawer(&s_info);
	return (0);
}
