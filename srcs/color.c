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
