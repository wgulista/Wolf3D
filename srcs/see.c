#include "../includes/wolf3d.h"

void	see_up(t_env *e)
{
	e->w->plane_x = e->w->dir_x + e->w->cameraX + 0.1;
}

void	see_down(t_env *e)
{
	e->w->plane_y -= 0.5;
}