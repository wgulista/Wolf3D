#include "../includes/wolf3d.h"

void		move_up(t_env *e)
{
	(void)e;
}

void		move_right(t_env *e)
{
	(void)e;
}

void		move_down(t_env *e)
{
	(void)e;
}

void		move_left(t_env *e)
{
	(void)e;
}

void		move(t_env *e)
{
	if (e->key.up)
		move_up(e);
	if (e->key.right)
		move_right(e);
	if (e->key.down)
		move_down(e);
	if (e->key.left)
		move_left(e);
}