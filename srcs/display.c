/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:08:08 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/09 13:08:10 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		pixel_put_to_image(t_env *e, double x, double y, int color)
{
	int		pos;

	pos = (((int)y * e->img.sline) + ((int)x * (e->img.bpp / 8)));
	if (e->img.endian)
	{
		e->img.data[pos] = (color & 0xFF0000) >> 16;
		e->img.data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img.data[pos + 2] = (color & 0x0000FF);
	}
	else
	{
		e->img.data[pos] = (color & 0x0000FF);
		e->img.data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img.data[pos + 2] = (color & 0xFF0000) >> 16;
	}
}

void		draw_sky_ground(t_env *e, int x, int end)
{
	int		y;

	y = end;
	while (y < HEIGHT)
	{
		pixel_put_to_image(e, x, HEIGHT - y - 1, 0xCFECF2);
		pixel_put_to_image(e, x, y, 0xCCAAFF);
		y++;
	}
}

int			draw_vertical_line(t_env *e, double x, int start, int end)
{
	int		y;

	y = start;
	while (y < end)
	{
		pixel_put_to_image(e, x, y, e->color);
		y++;
	}
	draw_sky_ground(e, x, end);
	return (1);
}
