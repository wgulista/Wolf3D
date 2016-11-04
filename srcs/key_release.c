#include "../includes/wolf3d.h"

int				key_release(int keycode, t_env *e)
{
	(void)keycode;
	expose_hook(e);
	return (0);
}