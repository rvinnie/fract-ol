#include "fractol.h"

double	change_range(double range)
{
	double	ret;

	ret = range * .2;
	return (ret);
}

unsigned int	rgb(int r, int g, int b)
{
	unsigned int	ans;

	ans = (r) % 255 * 256 * 256 + (g) % 255 * 256 + (b) % 255;
	return (ans);
}

unsigned int	take_color(t_info s_info, int n)
{
	unsigned int	color;

	if (s_info.color == 1)
		color = rgb(n * 2, 255, 255);
	else if (s_info.color == 2)
		color = rgb(255, n * 2, 255);
	else if (s_info.color == 3)
		color = rgb(255, 255, n * 2);
	else if (s_info.color == 4)
		color = rgb(n * 2, 0, n * 2);
	else if (s_info.color == 5)
		color = rgb(n * 2, n, n + 30);
	if (n == s_info.max_iter)
	{
		if (s_info.color == 5)
			color = COLOR_WHITE;
		else
			color = COLOR_BLACK;
	}
	return (color);
}

int	cmp_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '1' && !arg[i + 1])
		return (1);
	else if (arg[i] == '2' && !arg[i + 1])
		return (2);
	else
		return (-1);
}

void	print_list(void)
{
	printf("List of available parameters:\n");
	printf("1 - Julia Set\n2 - Mandelbrot Set\n");
	exit(0);
}
