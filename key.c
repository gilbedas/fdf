/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:03:51 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 17:34:48 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_bend(int keycode, t_param *p)
{
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit (0);
	}
	else if (keycode == 123)
	{
		p->OX = p->OX - 50;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	else if (keycode == 124)
	{
		p->OX = p->OX + 50;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	else if (keycode == 125)
	{
		p->OY = p->OY + 50;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	else if (keycode == 126)
	{
		p->OY = p->OY - 50;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	else
		key_test(p, keycode);
	return (0);
}

void	key_test(t_param *p, int keycode)
{
	if (keycode == 1)
	{
		if (p->zoom == 1)
			p->zoom -= 3;
		else
			p->zoom = p->zoom - 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	if (keycode == 13)
	{
		if (p->zoom == -1)
			p->zoom += 3;
		else
			p->zoom = p->zoom + 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	if (keycode == 17)
	{
		p->t = p->t + 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	if (keycode == 5)
	{
		if (p->t > 0)
			p->t -= 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	if (keycode == 91)
	{
		p->angs += 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	if (keycode == 84)
	{
		p->angs -= 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	if (keycode == 86)
	{
		p->angc += 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
	if (keycode == 88)
	{
		p->angc -= 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_put(p);
	}
}
