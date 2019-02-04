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

int		key_press(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
		read_input(&mlx, "julia");
	else if (keycode == 19)
		read_input(&mlx, "mandelbrot");
	else if (keycode == 20)
		read_input(&mlx, "burningship");
	else if (keycode == 15)
		reset(mlx);
	thread(mlx);
	return (0);
}

int		key_down(int key, t_mlx *mlx)
{
	if (key == 0x45)
		mlx->max_iteration += 10;
	else if (key == 0x4E)
		mlx->max_iteration -= 10;
	else if (key == 0x0D)
		mlx->cam->offset_y -= ((WIN_HEIGHT / 2)) / ((WIN_HEIGHT / 2) * mlx->cam->zoom) * 0.05;
	else if (key == 0x01)
		mlx->cam->offset_y += ((WIN_HEIGHT / 2)) / ((WIN_HEIGHT / 2) * mlx->cam->zoom) * 0.05;
	else if (key == 0x00)
		mlx->cam->offset_x -= ((WIN_WIDTH / 2)) / ((WIN_WIDTH / 2) * mlx->cam->zoom) * 0.05;
	else if (key == 0x02)
		mlx->cam->offset_x += ((WIN_WIDTH / 2)) / ((WIN_WIDTH / 2) * mlx->cam->zoom) * 0.05;
	thread(mlx);
	return (0);
}

void	reset(t_mlx *mlx)
{
	mlx->mouse->pressed = 0;
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->zoom = 1;
	mlx->cam->offset_x = 0;
	mlx->cam->offset_y = 0;
	mlx->set->r = 0.5;
	mlx->set->i = 0.5;
	mlx->max_iteration = 10;
}

int		mouse_zoom(int button, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		mlx->cam->zoom *= 1.05;
		thread(mlx);
	}
	else if (button == 5)
	{
		mlx->cam->zoom /= 1.05;
		thread(mlx);
	}
	if (y < 0)
		return (0);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->pressed == 0)
	{
		mlx->set->i += .00025 *
			(double)(mlx->mouse->prev_x - x) / mlx->cam->zoom;
		mlx->set->r += .00025 *
			(double)(mlx->mouse->prev_y - y) / mlx->cam->zoom;
	}
	thread(mlx);
	return (0);
}
