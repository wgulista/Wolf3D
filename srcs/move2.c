/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:09:46 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/09 13:09:48 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		straffe_left(t_env *e)
{
	if (map_1((int)(e->w->pos_x - e->w->plane_x * 0.1),
		(int)(e->w->pos_y)) == 0)
		e->w->pos_x -= e->w->plane_x * 0.1;
	if ((map_1((int)(e->w->pos_x),
		(int)(e->w->pos_y - e->w->plane_y * 0.1)) == 0))
		e->w->pos_y -= e->w->plane_y * 0.1;
}

void		straffe_right(t_env *e)
{
	if ((map_1((int)(e->w->pos_x + e->w->plane_x * 0.1),
		(int)(e->w->pos_y)) == 0))
		e->w->pos_x += e->w->plane_x * 0.1;
	if ((map_1((int)(e->w->pos_x),
		(int)(e->w->pos_y + e->w->plane_y * 0.1)) == 0))
		e->w->pos_y += e->w->plane_y * 0.1;
}
