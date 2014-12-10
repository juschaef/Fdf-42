/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 11:40:36 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/10 11:38:50 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_left(t_win *win)
{
	win->angle += 0.05;
	erase(win);
}

void	rotate_right(t_win *win)
{
	win->angle -= 0.05;
	erase(win);
}

void	pivote_z(t_win *win)
{
	win->rot = BET_Z;
	erase(win);
}

void	pivote_y(t_win *win)
{
	win->rot = BET_Y;
	erase(win);
}

void	pivote_x(t_win *win)
{
	win->rot = BET_X;
	erase(win);
}
