/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:50:12 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 16:48:16 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init(t_param *p)
{
	p->YC = p->YC + 1;
	p->l.xb = find_x(p);
	p->l.yb = find_y(p);
	p->YC = p->YC - 1;
	p->l.xa = find_x(p);
	p->l.ya = find_y(p);
}

void		vertical_line(t_param *p)
{
	int		dx;
	int		dy;

	init(p);
	dx = p->l.xb - p->l.xa;
	dy = p->l.yb - p->l.ya;
	if (dx > 0)
	{
		DXS(p, dx, dy);
	}
	else if (dx < 0)
	{
		DXI(p, dx, dy);
	}
	else
	{
		if (dy > 0)
			while (p->l.ya != p->l.yb)
			{
				mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
				p->l.ya += 1;
			}
		else
			while (p->l.ya != p->l.yb)
			{
				mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
				p->l.ya -= 1;
			}
	}
}
