/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:35:13 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 18:39:09 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_import_map(t_win *win)
{
	win->init = mlx_init();
	win->win = mlx_new_window(win->init, WIN_W, WIN_H, "FdF");
	win->pad = 15;
	win->opt = ISO;
	win->pad_h = 5;
	win->move_lr = 1;
	win->move_ud = 1;
	win->draw_type = PUT;
	win->img = mlx_new_image(win->init, WIN_W, WIN_H);
	win->data = mlx_get_data_addr(win->img, &(win->color), &(win->size),
		&(win->endian));
	win->map = create_map(win);
	mlx_key_hook(win->win, key_hook, win);
	mlx_mouse_hook(win->win, mouse_hook, win);
	mlx_expose_hook(win->win, expose_hook, win);
	mlx_loop(win->init);
	(void)win;
}

int		expose_hook(t_win *win)
{
	calcule_coord(win);
	if (win->draw_type == PUT)
		mlx_put_image_to_window(win->init, win->win, win->img, 0, 0);
	return (0);
	(void)win;
}

int		key_hook(int keycode, t_win *win)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65451)
		zoom_map(win);
	if (keycode == 65453)
		de_zoom_map(win);
	if (keycode == 65362)
		move_image_up(win);
	if (keycode == 65364)
		move_image_down(win);
	if (keycode == 65361)
		move_image_left(win);
	if (keycode == 65363)
		move_image_right(win);
	if (keycode == 112)
		para_projection(win);
	if (keycode == 105)
		iso_projection(win);
	if (keycode == 100)
		draw_method(win);
	if (keycode == 102)
		put_method(win);
	if (keycode == 111)
		vanilla_mode(win);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_win *win)
{
	printf("bouton : %d\n", button);
	if (button == 5)
		increase_pike(win);
	if (button == 4)
		decrease_pike(win);
	(void)x;
	(void)y;
	return (0);
}