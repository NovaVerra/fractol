/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:11:11 by llee              #+#    #+#             */
/*   Updated: 2019/02/06 13:39:48 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_set(t_mlx *mlx, int keycode)
{
	if (keycode == 18)
		read_input(&mlx, "julia");
	else if (keycode == 19)
		read_input(&mlx, "mandelbrot");
	else if (keycode == 20)
		read_input(&mlx, "burningship");
}

void	shift_cam(t_mlx *mlx, int keycode)
{
	if (keycode == 13)
		mlx->cam->offset_y -= (WIN_HEIGHT / 2) / ((WIN_HEIGHT / 2) * mlx->cam->zoom) * 0.15;
	else if (keycode == 1)
		mlx->cam->offset_y += (WIN_HEIGHT / 2) / ((WIN_HEIGHT / 2) * mlx->cam->zoom) * 0.15;
	else if (keycode == 0)
		mlx->cam->offset_x -= (WIN_WIDTH / 2) / ((WIN_WIDTH / 2) * mlx->cam->zoom) * 0.15;
	else if (keycode == 2)
		mlx->cam->offset_x += (WIN_WIDTH / 2) / ((WIN_WIDTH / 2) * mlx->cam->zoom) * 0.15;
}

void	iterate_set(t_mlx *mlx, int keycode)
{
	if (keycode == 67)
		mlx->max_iteration += 10;
	else if (keycode == 75)
		mlx->max_iteration -= 10;
}

void	zoom_cam(t_mlx *mlx, int keycode)
{
	if (keycode == 69 || keycode == 4)
		mlx->cam->zoom *= 1.15;
	else if (keycode == 78 || keycode == 5)
		mlx->cam->zoom /= 1.15;
}

void	reset(t_mlx *mlx)
{
	mlx->mouse->pressed = 0;
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->zoom = 0.5;
	mlx->cam->offset_x = 0;
	mlx->cam->offset_y = 0;
	mlx->set->r = 0.5;
	mlx->set->i = 0.5;
	mlx->max_iteration = 10;
}
