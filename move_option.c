/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:18:29 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 17:53:52 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_image_up(t_win *win)
{
	win->move_ud -= 10;
	erase(win);
}

void	move_image_down(t_win *win)
{
	win->move_ud += 10;
	erase(win);
}

void	move_image_left(t_win *win)
{
	win->move_lr -= 10;
	erase(win);
}

void	move_image_right(t_win *win)
{
	win->move_lr += 10;
	erase(win);
}
