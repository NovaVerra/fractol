/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:11:11 by llee              #+#    #+#             */
/*   Updated: 2019/02/05 15:11:16 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_mlx *mlx, int key)
{
	if (key == 69 || key == 4)
		mlx->cam->zoom += 1.5;
	if (key == 78 || key == 5)
		mlx->cam->zoom -= 1.5;
	thread(mlx);
}

void	shift(t_mlx *mlx, int key)
{
	if (key == 126)
		mlx->cam->offset_y -= 8;
	if (key == 125)
		mlx->cam->offset_y += 8;
	if (key == 123)
		mlx->cam->offset_x -= 8;
	if (key == 124)
		mlx->cam->offset_x += 8;
	render(mlx);
}

void	cam_reset(t_mlx *mlx)
{
	mlx->mouse->pressed = 0;
	mlx->max_iteration = 10;
	mlx->set->r = 0.5;
	mlx->set->i = 0.5;
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->zoom = 0.5;
	mlx->cam->offset_x = 0;
	mlx->cam->offset_y = 0;
}