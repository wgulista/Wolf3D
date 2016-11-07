#include "../includes/wolf3d.h"

void		straffe_left(t_env *e)
{
	if (e->worldmap[(int)(e->w->pos_x - e->w->plane_x * 0.5)]
			[(int)(e->w->pos_y)] == 0)
		e->w->pos_x -= e->w->plane_x * 0.5;
	if (e->worldmap[(int)(e->w->pos_x)][(int)(e->w->pos_y - e->w->plane_y
				* 0.5)] == 0)
		e->w->pos_y -= e->w->plane_y * 0.5;
}

void		straffe_right(t_env *e)
{
	if (e->worldmap[(int)(e->w->pos_x + e->w->plane_x * 0.5)]
			[(int)(e->w->pos_y)] == 0)
		e->w->pos_x += e->w->plane_x * 0.5;
	if (e->worldmap[(int)(e->w->pos_x)][(int)(e->w->pos_y + e->w->plane_y
				* 0.5)] == 0)
		e->w->pos_y += e->w->plane_y * 0.5;
}