/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:12:17 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 17:40:42 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_param(t_param *p)
{

	p->width =  1280;
	p->high = 900;
	p->g.xmax = 0;
	p->g.ymax = 0;
	p->OX = 500;
	p->OY = 300;
	p->XC = 0;
	p->YC = 0;
	p->zoom = -2;
	p->angc = 0;
	p->angs = 90;
	p->t = 4;
}

int		main(int argc, char **argv)
{
	t_param	p;
	int		i;
	int		j;
	int		fd;

	init_param(&p);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("error\n");
			return(0);
		}
		i = pars(&p, fd);
		close(fd);
		if (i == 1)
		{
			p.mlx = mlx_init();
			p.win = mlx_new_window(p.mlx, p.width, p.high, "fdf");
			mlx_put(&p);
			mlx_key_hook(p.win, key_bend, &p);
			mlx_loop(p.mlx);
		}
		i = 0;
	}
	return (0);
}
