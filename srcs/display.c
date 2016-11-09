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

	pos = ((y * e->img.sline) + (x * (e->img.bpp / 8)));
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
		pixel_put_to_image(e, x, HEIGHT - y - 1, 0x0000CC);
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
	draw_sky_ground(e, x, end);
	return (1);
}
