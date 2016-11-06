#include "../includes/wolf3d.h"

int			mouse_motion(int x, int y, t_env *e)
{
	int		middle;
	double	olddirx;
	double	oldplanex;
	(void)y;

	middle = WIDTH / 2;
	if (x >= middle && x <= WIDTH)
	{
		olddirx = e->w->dir_x;
		e->w->dir_x = e->w->dir_x * cos(-1 * 0.01) - e->w->dir_y * sin(-1 * 0.01);
		e->w->dir_y = olddirx * sin(-1 * 0.01) + e->w->dir_y * cos(-1 * 0.01);
		oldplanex = e->w->plane_x;
		e->w->plane_x = e->w->plane_x * cos(-1 * 0.01) - e->w->plane_y * sin(-1 * 0.01);
		e->w->plane_y = oldplanex * sin(-1 * 0.01) + e->w->plane_y * cos(-1 * 0.01);
	}
	if (x >= 0 && x <= middle)
	{
		olddirx = e->w->dir_x;
		e->w->dir_x = e->w->dir_x * cos(0.01) - e->w->dir_y * sin(0.01);
		e->w->dir_y = olddirx * sin(0.01) + e->w->dir_y * cos(0.01);
		oldplanex = e->w->plane_x;
		e->w->plane_x = e->w->plane_x * cos(0.01) - e->w->plane_y * sin(0.01);
		e->w->plane_y = oldplanex * sin(0.01) + e->w->plane_y * cos(0.01);
	}
	expose_hook(e);
	return (1);
}