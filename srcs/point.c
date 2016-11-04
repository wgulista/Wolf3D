#include "../includes/wolf3d.h"

t_v2di		set_point_i(int x, int y)
{
	t_v2di	tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp); 
}

t_v2dd		set_point_d(double x, double y)
{
	t_v2dd	tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}