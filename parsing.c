/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:27:39 by ghery             #+#    #+#             */
/*   Updated: 2016/04/11 15:40:40 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pars(t_param *p, int fd)
{
	char	*buffer;
	char	*str;
	int		ret;

	str = (char *)ft_memalloc(1);
	buffer = (char *)ft_memalloc(1);
	while ((ret = read(fd, buffer, 1)) > 0)
	{
		str = ft_strjoin(str, buffer);
	}
	if (ret == -1)
		return(-1);
	fill_grid(p, str);
	return(1);
}

void	fill_grid(t_param *p, char *str)
{
	int		i;
	int		j;
	int		k;
	int		c;
	char	nb[10];

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			p->g.ymax += 1;
		if (str[i] > 47 && str[i] < 58 && str[i + 1] == ' ')
			p->g.xmax += 1;
		i++;
	}
	p->g.xmax =(p->g.xmax / p->g.ymax) + 1;
	i = -1;
	p->g.grid = (int **)ft_memalloc(sizeof(int *) * p->g.ymax);
	while ((i++) < p->g.ymax)
		p->g.grid[i] = (int *)ft_memalloc(sizeof(int) * p->g.xmax);
	i = 0;
	j = 0;
	c = 0;
	while (c < strlen(str))
	{
		k = 0;
		while (str[c] > 47 && str[c] < 58)
		{
			nb[k] = str[c];
			c++;
			if ((str[c] == ' ' || str[c] == '\n') && j < p->g.xmax)
			{
				p->g.grid[i][j] = ft_atoi(nb);
				j++;
				if (str[c] == '\n' && i < p->g.ymax)
				{
					j = 0;
					i++;
				}
			}
			k++;
		}
		c++;
	}
}
