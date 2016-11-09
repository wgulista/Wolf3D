/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:08:49 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/09 13:08:51 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				expose_hook(t_env *e)
{
	draw_map(e);
	move(e);
	if (e->help == 1)
		display_menu(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	display_menu(e);
	return (0);
}
