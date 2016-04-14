/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:43:16 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 16:14:42 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_put(t_param *p)
{
	p->YC = 0;
	p->XC = 0;
	while (p->YC < p->g.ymax)
	{
		p->XC = 0;
		while (p->XC < p->g.xmax)
		{
			mlx_pixel_put(p->mlx, p->win, find_x(p), find_y(p), 0xFFFFFF);
			p->XC += 1;
		}
		p->YC += 1;
	}
	p->YC = 0;
	p->XC = 0;
	while (p->YC < p->g.ymax)
	{
		p->XC = 0;
		while (p->XC < p->g.xmax)
		{
			if (p->XC + 1 < p->g.xmax)
				horizontal_line(p);
			if (p->YC + 1 < p->g.ymax)
				vertical_line(p);
			p->XC += 1;
		}
		p->YC += 1;
	}
}

int		color(t_param *p)
{
	int		c;

	if (p->g.grid[p->YC][p->XC] >= 10)
	{
		c = 0xFFFFFF;
	}
	else if (p->g.grid[p->YC][p->XC] >= 5)
		c = 0x562B08;
	else if (p->g.grid[p->YC][p->XC] > 0)
		c = 0x66CC00;
	else 
		c = 0x0000CC;
	return(c);
}
