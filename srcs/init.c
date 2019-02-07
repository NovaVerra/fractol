/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:57:15 by llee              #+#    #+#             */
/*   Updated: 2019/01/28 08:57:24 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()) ||
		!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, "llee's Fract'ol")) ||
		!(mlx->set = ft_memalloc(sizeof(t_set))) ||
		!(mlx->cam = ft_memalloc(sizeof(t_cam))) ||
		!(mlx->image = init_image(mlx)) ||
		!(mlx->mouse = ft_memalloc(sizeof(t_mouse))))
		return (clean_mlx(mlx));
	mlx->max_iteration = 10;
	mlx->color = 1;
	mlx->set->r = 0.5;
	mlx->set->i = 0.5;
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->offset_x = 0;
	mlx->cam->offset_y = 0;
	mlx->cam->zoom = 0.5;
	mlx->mouse->pressed = 0;
	return (mlx);
}

t_image	*init_image(t_mlx *mlx)
{
	t_image		*image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(image->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (clean_image(mlx, image));
	image->ptr = mlx_get_data_addr(image->img, &image->bpp, &image->line,
			&image->endian);
	image->bpp /= 8;
	return (image);
}
