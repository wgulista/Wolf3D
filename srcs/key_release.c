/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:57:26 by wgulista          #+#    #+#             */
/*   Updated: 2016/11/08 15:57:28 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				key_release(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->key.up = 0;
	if (keycode == KEY_RIGHT)
		e->key.right = 0;
	if (keycode == KEY_DOWN)
		e->key.down = 0;
	if (keycode == KEY_LEFT)
		e->key.left = 0;
	expose_hook(e);
	return (0);
}
