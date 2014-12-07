/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 17:55:51 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 16:58:17 by juschaef         ###   ########.fr       */
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

void		calculate(t_win *win, t_point *point)
{
	int act_x;
	int act_y;
	int act_z;

	act_x = point->d3x * win->pad;
	act_y = point->d3y * win->pad;
	act_z = point->d3z * win->pad_h;
	if (win->opt == ISO)
	{
		point->d2x = act_x - act_y + WIN_W * 0.5;
		point->d2y = -act_z + act_x * 0.5 + act_y * 0.5 + WIN_H * 0.3;
	}
	else if (win->opt == PARA)
	{
		point->d2x = act_x - act_z + WIN_W * 0.5;
		point->d2y = act_y + -1 * 0.5 * act_z + WIN_H * 0.3;
	}
}
