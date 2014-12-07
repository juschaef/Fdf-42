/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:08:11 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 17:55:51 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	para_projection(t_win *win)
{
	win->opt = PARA;
	erase(win);
}

void	iso_projection(t_win *win)
{
	win->opt = ISO;
	erase(win);
}

void	draw_method(t_win *win)
{
	win->draw_type = DRAW;
	erase(win);
}

void	put_method(t_win *win)
{
	win->draw_type = PUT;
	erase(win);
}

void	vanilla_mode(t_win *win)
{
	win->pad = 15;
	win->opt = ISO;
	win->pad_h = 5;
	win->move_lr = 1;
	win->move_ud = 1;
	win->draw_type = PUT;
	erase(win);
}
