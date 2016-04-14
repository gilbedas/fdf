/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:35:27 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 17:12:09 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	DXS_DYS(t_param *p, int dx, int dy)
{
	int e;

	if (dx >= dy)
	{
		e = dx;
		while (p->l.xa != p->l.xb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e -= dy;
			if (e < 0)
			{
				p->l.ya += 1;
				e += dx;
			}
			p->l.xa += 1;
		}
	}
	else
	{
		e = dy;
		while (p->l.ya != p->l.yb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e -= dx;
			if (e < 0)
			{
				p->l.xa += 1;
				e += dy;
			}
			p->l.ya += 1;
		}
	}
}

void	DXS_DYI(t_param *p, int dx, int dy)
{
	int e;

	if (dx >= -dy)
	{
		e = dx;
		while (p->l.xa != p->l.xb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e += dy;
			if (e < 0)
			{
				p->l.ya -= 1;
				e += dx;
			}
			p->l.xa += 1;
		}
	}
	else
	{
		e = dy;
		while (p->l.ya != p->l.yb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e += dx;
			if (e >= 0)
			{
				p->l.xa += 1;
				e += dy;
			}
			p->l.ya -= 1;
		}
	}
}

void	DXI_DYS(t_param *p, int dx, int dy)
{
	int e;

	if (-dx >= dy)
	{
		e = dx;
		while (p->l.xa != p->l.xb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e += dy;
			if (e >= 0)
			{
				p->l.ya += 1;
				e += dx;
			}
			p->l.xa -= 1;
		}
	}
	else
	{
		e = dy;
		while (p->l.xa != p->l.xb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e += dx;
			if (e <= 0)
			{
				p->l.xa -= 1;
				e += dy;
			}
			p->l.ya += 1;
		}

	}
}


void	DXI_DYI(t_param *p, int dx, int dy)
{
	int e;

	if (dx <= dy)
	{
		e = dx;
		while (p->l.xa != p->l.xb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e -= dy;
			if (e >= 0)
			{
				p->l.ya -= 1;
				e += dx;
			}
			p->l.xa -= 1;
		}
	}
	else
	{
		e = dy;
		while (p->l.ya != p->l.yb)
		{
			mlx_pixel_put(p->mlx, p->win, p->l.xa, p->l.ya, color(p));
			e -= dx;
			if (e >= 0)
			{
				p->l.xa -= 1;
				e += dy;
			}
			p->l.ya -= 1;
		}
	}
}

