/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:08:30 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/09 13:08:32 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		init_arrow(t_arrow *key)
{
	key->up = 0;
	key->right = 0;
	key->down = 0;
	key->left = 0;
}

void		init_img_value(t_env *e)
{
	if (!(e->img.img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		ft_msg_error("CREATE IMAGE FAIL");
	if (!(e->img.data = mlx_get_data_addr(e->img.img, &(e->img.bpp),
		&(e->img.sline), &(e->img.endian))))
		ft_msg_error("GET DATA ADDR FAIL");
}

t_w3d		*init_w3d(void)
{
	t_w3d	*w;

	w = (t_w3d*)malloc(sizeof(t_w3d) * 1);
	w->pos_x = 18;
	w->pos_y = 18;
	w->pos_z = 6;
	w->dir_x = -1;
	w->dir_y = 0;
	w->plane_x = 0.0;
	w->plane_y = 0.66;
	return (w);
}

void		init_env_value(t_env *e)
{
	init_arrow(&e->key);
	e->w = init_w3d();
	e->help = 0;
}
