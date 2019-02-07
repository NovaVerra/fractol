/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:43:18 by llee              #+#    #+#             */
/*   Updated: 2019/01/28 16:43:26 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_color(int i, t_thread *thrd, int x, int y)
{
	if (i == 0)
		img_put_pixel(thrd->mlx->image, x, y, 0x3c3c3c);
	else if (i == -1)
		img_put_pixel(thrd->mlx->image, x, y, 0x080808);
	else
		img_put_pixel(thrd->mlx->image, x, y, 0x4242FF >> (i % 42));
}

void	message(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50, 0xFFFFFF,
	"- LEFT CLICK + DRAG = shift real and imaginery number");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 75, 0xFFFFFF,
	"- SCROLLWHEEL = zoom in/out");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 100, 0xFFFFFF,
	"- W/S = pan up/down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 125, 0xFFFFFF,
	"- A/D = pan left/right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 150, 0xFFFFFF,
	"- ADD/SUBTRACT ON NUMPAD = zoom in/out");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 175, 0xFFFFFF,
	"- / | * ON NUMPAD = zoom in/out");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 200, 0xFFFFFF,
	"- R = reset");
	message_2(mlx);
}

void	message_2(t_mlx *mlx)
{
	int	i;

	i = 34;
	while (++i < 235)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 35, i, 0xFFFFFF);
	i = 34;
	while (++i < 600)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, 35, 0xFFFFFF);
	i = 34;
	while (++i < 235)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 600, i, 0xFFFFFF);
	i = 34;
	while (++i < 600)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, 235, 0xFFFFFF);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1810, 1030, 0xFFFFFF, "by llee");
}