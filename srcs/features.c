/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:09:01 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/09 13:09:02 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				quit_program(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
	return (0);
}

void			display_menu(t_env *e)
{
	int			i;
	int			j;

	i = 5;
	while (i++ < 400)
	{
		j = 5;
		while (j++ < 100)
			pixel_put_to_image(e, i, j, 0x000000);
	}
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFF00, "h : help");
	if (e->help == 1)
	{
		mlx_string_put(e->mlx, e->win, 10, 30, 0xF8F8FF,
			"Echap - Croix : Quitter le programme");
		mlx_string_put(e->mlx, e->win, 10, 45, 0xF8F8FF,
			"Fleche        : Se deplacer");
	}
}
