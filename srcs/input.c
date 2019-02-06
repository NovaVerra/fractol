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
	else if (keycode == 13)
		mlx->cam->offset_y -= (WIN_HEIGHT / 2) / ((WIN_HEIGHT / 2) * mlx->cam->zoom) * 0.15;
	else if (keycode == 1)
		mlx->cam->offset_y += (WIN_HEIGHT / 2) / ((WIN_HEIGHT / 2) * mlx->cam->zoom) * 0.15;
	else if (keycode == 0)
		mlx->cam->offset_x -= (WIN_WIDTH / 2) / ((WIN_WIDTH / 2) * mlx->cam->zoom) * 0.15;
	else if (keycode == 2)
		mlx->cam->offset_x += (WIN_WIDTH / 2) / ((WIN_WIDTH / 2) * mlx->cam->zoom) * 0.15;
	else if (keycode == 67)
		mlx->max_iteration += 10;
	else if (keycode == 75)
		mlx->max_iteration -= 10;
	else if (keycode == 69)
		mlx->cam->zoom *= 1.15;
	else if (keycode == 78)
		mlx->cam->zoom /= 1.15;
	else if (keycode == 15)
		reset(mlx);
	thread(mlx);
	return (0);
}
