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
	init_img_value(e);
	init_env_value(e);
	if (init_texture(e) == -1)
		ft_msg_error("TEXTURE CREATION FAIL");
	mlx_hook(e->win, EXPOSE, EXPOSE_MASK, expose_hook, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESS_MASK, key_hook, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASE_MASK, key_release, e);
	mlx_hook(e->win, DESTROY_NOTIFY, DESTROY_MASK, quit_program, e);
	mlx_loop(e->mlx);
	return (0);
}
