#include "fractol.h"

int	cmp_arg(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '1' && !arg[i + 1])
		return (1);
	else if (arg[i] == '2' && !arg[i + 1])
		return (2);
	else
		return (-1);
}

void	my_pxl_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void clear_image(t_info *s_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_info->h)
	{
		j = 0;
		while (j < s_info->w)
			my_pxl_put(&s_info->img, j++, i, COLOR_BLACK);
		i++;
	}
}