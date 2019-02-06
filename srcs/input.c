/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:00:46 by llee              #+#    #+#             */
/*   Updated: 2019/01/28 11:00:54 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_press(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (keycode >= 18 && keycode <= 20)
		change_set(mlx, keycode);
	else if (keycode == 13 || (keycode >= 0 && keycode <= 2))
		shift_cam(mlx, keycode);
	else if (keycode == 67 || keycode == 75)
		iterate_set(mlx, keycode);
	else if (keycode == 69 || keycode == 78)
		zoom_cam(mlx, keycode);
	else if (keycode == 15)
		reset(mlx);
	thread(mlx);
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (button >= 4 && button <= 5)
		zoom_cam(mlx, button);
	if (y < 0)
		return (0);
	if (button == 1 && mlx->mouse->pressed == 1)
		mlx->mouse->pressed = 0;
	if (button == 1 && mlx->mouse->pressed == 0)
		mlx->mouse->pressed = 1;
	printf("%d\n", mlx->mouse->pressed);
	thread(mlx);
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->pressed == 1)
	{
		mlx->set->i += .00025 *
			(double)(mlx->mouse->prev_x - x) / mlx->cam->zoom;
		mlx->set->r += .00025 *
			(double)(mlx->mouse->prev_y - y) / mlx->cam->zoom;
	}
	thread(mlx);
	return (0);
}