#include "../includes/wolf3d.h"

void		straffe_left(t_env *e)
{
	if (e->worldmap[(int)(e->w->pos_x - e->w->plane_x * 0.1)]
			[(int)(e->w->pos_y)] == 0)
		e->w->pos_x -= e->w->plane_x * 0.1;
	if (e->worldmap[(int)(e->w->pos_x)][(int)(e->w->pos_y - e->w->plane_y
				* 0.1)] == 0)
		e->w->pos_y -= e->w->plane_y * 0.1;
}

void		straffe_right(t_env *e)
{
	if (e->worldmap[(int)(e->w->pos_x + e->w->plane_x * 0.1)]
			[(int)(e->w->pos_y)] == 0)
		e->w->pos_x += e->w->plane_x * 0.1;
	if (e->worldmap[(int)(e->w->pos_x)][(int)(e->w->pos_y + e->w->plane_y
				* 0.1)] == 0)
		e->w->pos_y += e->w->plane_y * 0.1;
}