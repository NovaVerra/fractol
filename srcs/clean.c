/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:01:53 by llee              #+#    #+#             */
/*   Updated: 2019/01/28 09:02:01 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_mlx	*clean_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->image != NULL)
		clean_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_image	*clean_image(t_mlx *mlx, t_image *image)
{
	if (image != NULL)
	{
		if (mlx->image != NULL)
			mlx_destroy_image(mlx->mlx_ptr, image->img);
		ft_memdel((void **)&image);
	}
	return (NULL);
}

void	reset_image(t_image *image)
{
	ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}
