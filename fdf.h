/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:38:55 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/11 14:54:17 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define WIN_H 1200
# define WIN_W 1900

# define BLUE 0x0041FF
# define BROWN 0xAD4F09
# define GREEN 0x25FF50
# define WHITE 0xFFFFFF
# define OPTION int
# define ISO 1
# define PARA 0
# define OFF 0
# define ON 1
# define PUT 0
# define DRAW 1
# define BET_X 0
# define BET_Y 1
# define BET_Z 2

typedef struct	s_point
{
	int			d3x;
	int			d3y;
	int			d3z;
	int			d2x;
	int			d2y;
	int			color;
}				t_point;

typedef struct	s_win
{
	void		*init;
	void		*win;
	char		*data;
	void		*img;
	int			size;
	int			endian;
	int			color;
	t_point		**map;
	char		*path;
	int			rot;
	int			map_w;
	int			map_h;
	int			max_z;
	int			legend_display;
	float		angle;
	int			pad;
	int			move_lr;
	int			move_ud;
	int			pad_h;
	OPTION		opt;
	int			draw_type;
}				t_win;

typedef struct	s_bresenham
{
	int			delta_x;
	int			sign_x;
	int			delta_y;
	int			sign_y;
	int			delta_error;
}				t_bres;

typedef struct	s_rotate_point
{
	float		act_px;
	float		act_py;
	float		act_pz;
	float		px;
	float		py;
	float		pz;
}				t_rp;

int				count_map_length(char **str);
int				len_tab(char *argv);
t_point			*create_int_table(t_win *win, char *str, int pos);
t_point			**create_map(t_win *win);
t_point			ft_create_point(char *str, int x, int y);
void			ft_import_map(t_win *win);
int				key_hook(int keycode, t_win *win);
int				expose_hook(t_win *win);
void			calcule_coord(t_win *win);
void			calculate(t_win *win, t_point *point);
int				choose_color(int p1, int p2, int max);
void			draw_map(t_win *win);
void			draw_line(t_win *win, t_point *point1, t_point *point2);
t_bres			*bres_construct(t_point *point1, t_point *point2, int max);
void			draw_point(t_win *win, int x, int y, int color);
void			zoom_map(t_win *win);
void			de_zoom_map(t_win *win);
void			move_image_up(t_win *win);
void			move_image_down(t_win *win);
void			move_image_left(t_win *win);
void			move_image_right(t_win *win);
int				check_x(t_win *win, int x);
int				check_y(t_win *win, int y);
int				create_x(t_win *win, int x);
int				create_y(t_win *win, int y);
void			iso_projection(t_win *win);
void			para_projection(t_win *win);
void			draw_method(t_win *win);
void			put_method(t_win *win);
void			erase(t_win *win);
void			vanilla_mode(t_win *win);
int				mouse_hook(int button, int x, int y, t_win *win);
void			increase_pike(t_win *win);
void			decrease_pike(t_win *win);
void			rotate_left(t_win *win);
void			rotate_right(t_win *win);
int				key_hook2(int keycode, t_win *win);
int				sq(int x);
void			calcule_rotation(t_win *win, t_point *point);
void			pivote_z(t_win *win);
void			pivote_y(t_win *win);
void			pivote_x(t_win *win);
void			put_info_to_windows(t_win *win);
void			put_meta(t_win *win);
void			hide_legend(t_win *win);
void			put_black_screen(t_win *win);

#endif
