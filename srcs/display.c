/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:56:42 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/08 16:10:48 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		pixel_put_to_image(t_env *e, int x, int y, int color)
{
	int		pos;

	pos = ((y * e->img[0].sline) + (x * (e->img[0].bpp / 8)));
	if (e->img[0].endian)
	{
		e->img[0].data[pos] = (color & 0xFF0000) >> 16;
		e->img[0].data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img[0].data[pos + 2] = (color & 0x0000FF);
	}
	else
	{
		e->img[0].data[pos] = (color & 0x0000FF);
		e->img[0].data[pos + 1] = (color & 0x00FF00) >> 8;
		e->img[0].data[pos + 2] = (color & 0xFF0000) >> 16;
	}
}

int			draw_vertical_line(t_env *e, int x, int start, int end)
{
	int		y;

	y = start;
	while (y < end)
	{
		if (e->w->side == 0)
		{
			if (e->w->step_x <= 0)
				pixel_put_to_image(e, x, y, 0xFF0000);
			else
				pixel_put_to_image(e, x, y, 0xFFFF00);
		}
		else
		{
			if (e->w->step_y <= 0)
				pixel_put_to_image(e, x, y, 0x00FF00);
			else
				pixel_put_to_image(e, x, y, 0x0000FF);
		}
		y++;
	}
	return (1);
}
