/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 17:55:51 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/10 11:40:15 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcule_coord(t_win *win)
{
	int i;
	int j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			calculate(win, &(win->map[j][i]));
			i++;
		}
		j++;
	}
	draw_map(win);
}

void		rotate_w(t_win *win, t_rp *rp)
{
	rp->px = rp->act_px * cos(win->angle) - rp->act_py * sin(win->angle);
	rp->py = rp->act_px * sin(win->angle) + rp->act_py * cos(win->angle);
	rp->pz = rp->act_pz;
}

void		rotate_y(t_win *win, t_rp *rp)
{
	rp->px = rp->act_px * cos(win->angle) + rp->act_pz * sin(win->angle);
	rp->py = rp->act_py;
	rp->pz = rp->act_px * -sin(win->angle) + rp->act_pz * cos(win->angle);
}

void		rotate_x(t_win *win, t_rp *rp)
{
	rp->px = rp->act_px;
	rp->py = rp->act_py * cos(win->angle) - rp->act_pz * sin(win->angle);
	rp->pz = rp->act_py * sin(win->angle) + rp->act_pz * cos(win->angle);
}

void		calculate(t_win *win, t_point *pt)
{
	t_rp	*rp;

	rp = (t_rp *)malloc(sizeof(t_rp));
	rp->act_px = pt->d3x * win->pad - (sqrt(sq(win->map_h) + sq(win->map_w)));
	rp->act_py = pt->d3y * win->pad - (sqrt(sq(win->map_h) + sq(win->map_w)));
	rp->act_pz = pt->d3z * win->pad_h;
	if (win->rot == BET_Z)
		rotate_w(win, rp);
	else if (win->rot == BET_Y)
		rotate_y(win, rp);
	else
		rotate_x(win, rp);
	if (win->opt == ISO)
	{
		pt->d2x = rp->px - rp->py + WIN_W * 0.5;
		pt->d2y = -rp->pz + rp->px * 0.5 + rp->py * 0.5 + WIN_H * 0.3;
	}
	else if (win->opt == PARA)
	{
		pt->d2x = rp->px - rp->pz + WIN_W * 0.5;
		pt->d2y = rp->py + -1 * 0.5 * rp->pz + WIN_H * 0.3;
	}
}
