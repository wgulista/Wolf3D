#include "../includes/wolf3d.h"

int				expose_hook(t_env *e)
{
	draw_map(e);
	move(e);
	if (e->help == 1)
		menu_put_to_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img[0].img, 0, 0);
	display_menu(e);
	return (0);
}