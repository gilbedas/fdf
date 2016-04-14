/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caly.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:23:36 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 17:25:34 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	YC_y(t_param *p)
{
	int	yc;

	yc = 24 * p->YC * sin(p->angs);
	return (yc);
}

static int	XC_y(t_param *p)
{
	int	xc;

	xc = 24 * p->XC * cos(p->angc);
	return (xc);
}

static int	cal(t_param *p)
{
	int	c;
	
	c = (p->OY + XC_y(p) + YC_y(p) - (p->t * p->g.grid[p->YC][p->XC]));
	return (c);
}

static int	zoom(t_param *p)
{
	int z;

	if (p->zoom > 0)
		z = cal(p) * p->zoom;
	else if (p->zoom < 0)
		z = cal(p) / ft_abs(p->zoom);
	return (z);
}

int			find_y(t_param *p)
{
	int	py;
	py = zoom(p);
	return (py);
}
