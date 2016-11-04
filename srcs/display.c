#include "../includes/wolf3d.h"

void		pixel_put_to_image(t_env *e, double x, double y, int color)
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

void		sky_put_to_image(t_env *e, double x, double y)
{
	int		pos;

	pos = ((y * e->img[0].sline) + (x * (e->img[0].bpp / 8)));
	e->img[0].data[pos] = e->img[1].data[pos];
	e->img[0].data[pos + 1] = e->img[1].data[pos + 1];
	e->img[0].data[pos + 2] = e->img[1].data[pos + 2];
}

void		ground_put_to_image(t_env *e, double x, double y)
{
	int		pos;

	pos = ((y * e->img[0].sline) + (x * (e->img[0].bpp / 8)));
	e->img[0].data[pos] = e->img[2].data[pos];
	e->img[0].data[pos + 1] = e->img[2].data[pos + 1];
	e->img[0].data[pos + 2] = e->img[2].data[pos + 2];
}

int 		draw_vertical_line(t_env *e, double x, int start, int end)
{
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < start)
			sky_put_to_image(e, x, y);
		else if (y >= start && y <= end)
			pixel_put_to_image(e, x, y, 0x659847);
		else if (y > end)
			ground_put_to_image(e, x, y);
		y++;
	}
	return (1);
}
