/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:57:35 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/08 16:06:07 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		move_up(t_env *e)
{
	if (generate_map((int)(e->w->pos_x + e->w->dir_x * 0.1), (int)(e->w->pos_y)) == 0)
		e->w->pos_x += e->w->dir_x * 0.1;
	if (generate_map((int)(e->w->pos_x), (int)(e->w->pos_y + e->w->dir_y * 0.1)) == 0)
		e->w->pos_y += e->w->dir_y * 0.1;
}

void		move_right(t_env *e)
{
	double	olddirx;
	double	oldplanex;

	mlx_clear_window(e->mlx, e->win);
	olddirx = e->w->dir_x;
	e->w->dir_x = e->w->dir_x * cos(-1 * 0.05) - e->w->dir_y * sin(-1 * 0.05);
	e->w->dir_y = olddirx * sin(-1 * 0.05) + e->w->dir_y * cos(-1 * 0.05);
	oldplanex = e->w->plane_x;
	e->w->plane_x = e->w->plane_x * cos(-1 * 0.05) - e->w->plane_y * sin(-1 * 0.05);
	e->w->plane_y = oldplanex * sin(-1 * 0.05) + e->w->plane_y * cos(-1 * 0.05);
}

void		move_down(t_env *e)
{
	if (generate_map((int)(e->w->pos_x - e->w->dir_x * 0.1), (int)(e->w->pos_y)) == 0)
		e->w->pos_x -= e->w->dir_x * 0.1;
	if (generate_map((int)(e->w->pos_x), (int)(e->w->pos_y - e->w->dir_y * 0.1)) == 0)
		e->w->pos_y -= e->w->dir_y * 0.1;
}

void		move_left(t_env *e)
{
	double	olddirx;
	double	oldplanex;

	mlx_clear_window(e->mlx, e->win);
	olddirx = e->w->dir_x;
	e->w->dir_x = e->w->dir_x * cos(0.05) - e->w->dir_y * sin(0.05);
	e->w->dir_y = olddirx * sin(0.05) + e->w->dir_y * cos(0.05);
	oldplanex = e->w->plane_x;
	e->w->plane_x = e->w->plane_x * cos(0.05) - e->w->plane_y * sin(0.05);
	e->w->plane_y = oldplanex * sin(0.05) + e->w->plane_y * cos(0.05);
}

void		move(t_env *e)
{
	if (e->key.up)
		move_up(e);
	else if (e->key.right)
		move_right(e);
	else if (e->key.down)
		move_down(e);
	else if (e->key.left)
		move_left(e);
}
