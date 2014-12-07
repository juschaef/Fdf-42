/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:32:25 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/03 19:54:20 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_win	win;

	win.path = argv[1];
	if (argc > 1 && argc < 3)
	{
		ft_import_map(&win);
	}
	else
		ft_putstr("Inser map here !");
	return (0);
}
