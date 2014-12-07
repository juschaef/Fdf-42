/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:19:08 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 18:34:05 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_map(t_win *win)
{
	win->pad += 1;
	erase(win);
}

void	de_zoom_map(t_win *win)
{
	win->pad -= 1;
	erase(win);
}
