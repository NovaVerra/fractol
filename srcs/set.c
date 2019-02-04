/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:16:26 by llee              #+#    #+#             */
/*   Updated: 2019/01/29 11:16:34 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			julia_set(int x, int y, t_thread *m)
{
	t_set	new;
	t_set	old;
	int		i;

	new = calc_cam(x, y, m);
	i = -1;
	while (++i < m->mlx->max_iteration)
	{
		old.r = new.r;
		old.i = new.i;
		old.r_2 = old.r * old.r;
		old.i_2 = old.i * old.i;
		new.r = (old.r_2) - (old.i_2) + m->mlx->set->r;
		new.i = ((old.r + old.r) * old.i) + m->mlx->set->i;
		new.r_2 = new.r * new.r;
		new.i_2 = new.i * new.i;
		if ((new.r_2 + new.i_2) > 4)
			return (i);
	}
	return (-1);
}

int			mandelbrot_set(int x, int y, t_thread *m)
{
	t_set	new;
	t_set	old;
	t_set	cur;
	int			i;

	cur = calc_cam(x, y, m);
	new.r = 0;
	new.i = 0;
	i = -1;
	while (++i < m->mlx->max_iteration)
	{
		old.r = new.r;
		old.i = new.i;
		old.r_2 = old.r * old.r;
		old.i_2 = old.i * old.i;
		new.r = (old.r_2) - (old.i_2) + cur.r;
		new.i = ((old.r + old.r) * old.i) + cur.i;
		new.r_2 = new.r * new.r;
		new.i_2 = new.i * new.i;
		if ((new.r_2 + new.i_2) > 4)
			return (i);
	}
	return (-1);
}

int			burningship_set(int x, int y, t_thread *m)
{
	t_set	new;
	t_set	old;
	t_set	cur;
	int			i;

	cur = calc_cam(x, y, m);
	new.r = 0;
	new.i = 0;
	i = -1;
	while (++i < m->mlx->max_iteration)
	{
		old.r = new.r;
		old.i = new.i;
		old.r_2 = old.r * old.r;
		old.i_2 = old.i * old.i;
		new.r = fabs((old.r_2) - (old.i_2)) + cur.r;
		new.i = fabs(((old.r + old.r) * old.i)) + cur.i;
		new.r_2 = new.r * new.r;
		new.i_2 = new.i * new.i;
		if ((new.r_2 + new.i_2) > 4)
			return (i);
	}
	return (-1);
}

t_set	calc_cam(int x, int y, t_thread *set)
{
	t_set	cur;

	cur.r = 1.5 * (x - (WIN_WIDTH / 2)) / ((WIN_WIDTH / 2) * set->mlx->cam->zoom) + set->mlx->cam->offset_x;
	cur.i = (y - (WIN_HEIGHT / 2)) / ((WIN_HEIGHT / 2) * set->mlx->cam->zoom) + set->mlx->cam->offset_y;
	return (cur);
}
