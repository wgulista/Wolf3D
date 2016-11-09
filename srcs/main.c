/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:57:29 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/08 15:59:04 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			main(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env) * 1)))
		ft_msg_error("Malloc Env Fail");
	if (!(e->mlx = mlx_init()))
		ft_msg_error("MLX INIT FAIL");
	if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf3D")))
		ft_msg_error("WINDOW CREATION FAIL");
	if (!(e->img[0].img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		ft_msg_error("CREATE IMAGE FAIL");
	if (!(e->img[0].data = mlx_get_data_addr(e->img[0].img, &(e->img[0].bpp), \
		&(e->img[0].sline), &(e->img[0].endian))))
		ft_msg_error("GET DATA ADDR FAIL");
	init_env_value(e);
	mlx_hook(e->win, EXPOSE, EXPOSE_MASK, expose_hook, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESS_MASK, key_hook, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASE_MASK, key_release, e);
	mlx_hook(e->win, DESTROY_NOTIFY, DESTROY_MASK, quit_program, e);
	mlx_do_key_autorepeaton(e->mlx);
	mlx_loop(e->mlx);
	return (0);
}
