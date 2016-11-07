#include "../includes/wolf3d.h"
#include <stdio.h>

void			init_value_w3d(t_w3d *w)
{
	w->cameraX = 2 * w->x / (double)(WIDTH) - 1;
	w->ray_pos_x = w->pos_x;
	w->ray_pos_y = w->pos_y;
	w->ray_dir_x = w->dir_x + w->plane_x * w->cameraX;
	w->ray_dir_y = w->dir_y + w->plane_y * w->cameraX;
	w->map_pos_x = (int)(w->ray_pos_x);
	w->map_pos_y = (int)(w->ray_pos_y);
	w->delta_dist_x = sqrt(1 + (w->ray_dir_y * w->ray_dir_y) / (w->ray_dir_x * w->ray_dir_x));
	w->delta_dist_y = sqrt(1 + (w->ray_dir_x * w->ray_dir_x) / (w->ray_dir_y * w->ray_dir_y));
	w->hit = 0;
}

void			check_ray_dist(t_w3d *w)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (w->ray_pos_x - (double)w->map_pos_x) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = ((double)w->map_pos_x + 1.0 - w->ray_pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (w->ray_pos_y - (double)w->map_pos_y) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = ((double)w->map_pos_y + 1.0 - w->ray_pos_y) * w->delta_dist_y;
	}
}

void			check_hit_wall(t_env *e, t_w3d *w)
{
	while (w->hit == 0)
	{
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->delta_dist_x;
			w->map_pos_x += w->step_x;
			w->side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->map_pos_y += w->step_y;
			w->side = 1;
		}
		if (e->worldmap[w->map_pos_x][w->map_pos_y] > 0)
			w->hit = 1;
	}
	if (w->side == 0)
		w->perp_wall_dist = fabs((w->map_pos_x - w->ray_pos_x + 
			(1 - w->step_x) / 2) / w->ray_dir_x);
	else
		w->perp_wall_dist = fabs((w->map_pos_y - w->ray_pos_y + 
			(1 - w->step_y) / 2) / w->ray_dir_y);	
}

void			calc_height_draw(t_w3d *w)
{
	w->line_height = abs((int)(HEIGHT / (w->perp_wall_dist)));
	w->start = -(w->line_height) / 2 + HEIGHT / 2;
	if (w->start < 0) 
		w->start = 0;
	w->end = w->line_height / 2 + HEIGHT / 2;
	if (w->end >= HEIGHT)
		w->end = HEIGHT - 1;
}

void			draw_map(t_env *e)
{
	e->w->x = 0;
	while (e->w->x < WIDTH)
	{
		init_value_w3d(e->w);
		check_ray_dist(e->w);
		check_hit_wall(e, e->w);
		calc_height_draw(e->w);
		draw_vertical_line(e, e->w->x, e->w->start, e->w->end);
		e->w->x++;
	}
}