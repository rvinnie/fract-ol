/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:34:09 by rvinnie           #+#    #+#             */
/*   Updated: 2021/08/02 16:34:11 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	kind = -1;
	if (argc > 1)
		kind = cmp_arg(argv[1]);
	if (argc == 1 || kind == -1)
	{
		print_list();
		return (0);
	}
	s_info.img.img = NULL;
	s_info.img.addr = NULL;
	s_info.mlx = NULL;
	s_info.win = NULL;
	s_info.kind = kind;
	s_info.w = WIDTH;
	s_info.h = HEIGHT;
	s_info.color = 1;
	s_info.max_iter = MAX_ITER;
	main_drawer(&s_info);
	return (0);
}
