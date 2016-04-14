/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 16:00:32 by ghery             #+#    #+#             */
/*   Updated: 2016/04/14 17:40:38 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef	struct		s_grid
{
	int				xmax;
	int				ymax;
	int 			**grid;
}					t_grid;

typedef	struct		s_line
{
	int				xa;
	int				ya;
	int				xb;
	int				yb;
}					t_line;

typedef struct		s_param
{
	void			*mlx;
	void			*win;
	int				width;
	int				high;
	int				OX;
	int				OY;
	int				XC;
	int				YC;
	int				LC;
	int				zoom;
	int				t;
	int				angc;
	int				angs;
	t_grid			g;
	t_line			l;
}					t_param;

void	init_param(t_param *p);
int		pars(t_param *p, int fd);
void	fill_grid(t_param *p, char *str);
void	mlx_put(t_param *p);
int		find_x(t_param *p);
int		find_y(t_param *p);
int		color(t_param *p);
void	horizontal_line(t_param *p);
void	vertical_line(t_param *p);
int		key_bend(int keycode, t_param *p);
void	key_test(t_param *p, int keycode);
void	DXS(t_param *p, int dx, int dy);
void	DXS_DYS(t_param *p, int dx, int dy);
void	DXS_DYI(t_param *p, int dx, int dy);
void	DXI(t_param *p, int dx, int dy);
void	DXI_DYS(t_param *p, int dx, int dy);
void	DXI_DYI(t_param *p, int dx, int dy);

#endif
