#include "../includes/wolf3d.h"

int				key_release(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->key.up = 0;
	if (keycode == KEY_RIGHT)
		e->key.right = 0;
	if (keycode == KEY_DOWN)
		e->key.down = 0;
	if (keycode == KEY_LEFT)
		e->key.left = 0;
	if (keycode == SPACE)
		e->w->pos_z -= 0.5 + e->w->end / 4;
	expose_hook(e);
	return (0);
}