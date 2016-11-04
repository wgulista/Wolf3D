#include "../includes/wolf3d.h"

int				quit_program(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img[0].img);
	mlx_destroy_image(e->mlx, e->img[1].img);
	/*mlx_destroy_image(e->mlx, e->img[2].img);
	mlx_destroy_image(e->mlx, e->img[3].img);
	mlx_destroy_image(e->mlx, e->img[4].img);*/			
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
	return (0);
}

void			display_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFF00, "h : help");
	if (e->help == 1)
	{
		mlx_string_put(e->mlx, e->win, 10, 30, 0xF8F8FF, \
			"Echap - Croix : Quitter le programme");
		mlx_string_put(e->mlx, e->win, 10, 45, 0xF8F8FF, \
			"Fleche        : Se deplacer");
		mlx_string_put(e->mlx, e->win, 10, 60, 0xF8F8FF, \
			"Touche T      : Change la couleur");
		mlx_string_put(e->mlx, e->win, 10, 75, 0xF8F8FF, \
			"Touch P       : Mettre en pause le jeu");
	}
}