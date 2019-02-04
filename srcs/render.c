/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:16:02 by llee              #+#    #+#             */
/*   Updated: 2019/01/28 09:16:12 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	thread(t_mlx *mlx)
{
	int			i;
	t_thread	arg[MAX_THREAD];
	pthread_t	thread[MAX_THREAD];

	reset_image(mlx->image);
	i = -1;
	while (++i < MAX_THREAD)
	{
		arg[i].id = i;
		arg[i].mlx = mlx;
		pthread_create(&thread[i], NULL, render, &arg[i]);
	}
	i = -1;
	while (++i < MAX_THREAD)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img, 0, 0);
}

void	*render(void *arg)
{
	int			x;
	int			y;
	t_thread	*cur;
	int			v;

	cur = (t_thread *)arg;
	y = WIN_HEIGHT / MAX_THREAD * cur->id;
	while (y < ((WIN_HEIGHT / MAX_THREAD) * (cur->id + 1)))
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			v = cur->mlx->get_set(x, y, cur);
			get_color(v, cur, x, y);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}

void	img_put_pixel(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(img->ptr + ((x + y * WIN_WIDTH) * img->bpp)) = color;
}
