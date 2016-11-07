#include "../includes/wolf3d.h"

int				key_hook2(int keycode, t_env *e)
{
	if (keycode == KEY_A)
		straffe_left(e);
	if (keycode == KEY_D)
		straffe_right(e);
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == H)
		e->help = (e->help == 1) ? 0 : 1;
	if (keycode == SPACE)
	{
		e->change_color++;
		if (e->change_color == 3)
			e->change_color = 0;
	}
	if (keycode == KEY_UP)
		e->key.up = 1;
	if (keycode == KEY_RIGHT)
		e->key.right = 1;
	if (keycode == KEY_DOWN)
		e->key.down = 1;
	if (keycode == KEY_LEFT)
		e->key.left = 1;
	if (keycode == 15)
		e->key.run = 2;
	if (keycode == ECHAP)
		quit_program(e);
	key_hook2(keycode, e);
	expose_hook(e);
	return (0);
}