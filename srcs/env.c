/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:57:12 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/08 15:57:14 by wgulista         ###   ########.fr       */
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

int			init_texture(t_env *e)
{
	if (!(e->img[1].data = mlx_get_data_addr(e->img[1].img, &(e->img[1].bpp),
		&(e->img[1].sline), &(e->img[1].endian))))
		return (-1);
	if (!(e->img[2].data = mlx_get_data_addr(e->img[2].img, &(e->img[2].bpp),
		&(e->img[2].sline), &(e->img[2].endian))))
		return (-1);
	return (0);
}

void		init_img_value(t_env *e)
{
	if (!(e->img[0].img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		ft_msg_error("CREATE IMAGE FAIL");
	if (!(e->img[0].data = mlx_get_data_addr(e->img[0].img, &(e->img[0].bpp),
		&(e->img[0].sline), &(e->img[0].endian))))
		ft_msg_error("GET DATA ADDR FAIL");
}

t_w3d		*init_w3d(void)
{
	t_w3d	*w;

	w = (t_w3d*)malloc(sizeof(t_w3d) * 1);
	w->pos_x = 20;
	w->pos_y = 10;
	w->pos_z = 6;
	w->dir_x = -1;
	w->dir_y = 0;
	w->plane_x = 0.0;
	w->plane_y = 0.66;
	return (w);
}

void		init_env_value(t_env *e)
{
	int		a;
	int		b;

	init_arrow(&e->key);
	e->w = init_w3d();
	e->help = 0;
	e->change_color = 0;
	e->img[1].img = mlx_xpm_file_to_image(e->mlx, "./img/ciel.xpm", &a, &b);
	e->img[2].img = mlx_xpm_file_to_image(e->mlx, "./img/ground.xpm", &a, &b);
}
