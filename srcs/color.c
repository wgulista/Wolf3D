/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:17:05 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/10 13:17:06 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		color_1(t_env *e)
{
	if (e->w->side == 0)
	{
		if (e->w->step_x <= 0)
			e->color = 0xFF0000;
		else
			e->color = 0xFFFF00;
	}
	else
	{
		if (e->w->step_y <= 0)
			e->color = 0x00FF00;
		else
			e->color = 0x0000FF;
	}
}

void		color_2(t_env *e)
{
	if (e->w->side == 0)
	{
		if (e->w->step_x <= 0)
			e->color = 0x5AB479;
		else
			e->color = 0x5AB4A6;
	}
	else
	{
		if (e->w->step_y <= 0)
			e->color = 0x5A95B4;
		else
			e->color = 0x5A68B4;
	}
}
