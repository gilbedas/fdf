/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:00:31 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 17:25:16 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	YC_x(t_param *p)
{
	int	yc;

	yc = 40 * p->YC * sin(p->angs);
	return (yc);
}

static int	XC_x(t_param *p)
{
	int	xc;

	xc = 40 * p->XC * cos(p->angc);
	return (xc);
}

static int	cal(t_param *p)
{
	int	c;
	
	c = (p->OX + XC_x(p) - YC_x(p));
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

int			find_x(t_param *p)
{
	int	px;
	px = zoom(p);
	return (px);
}
