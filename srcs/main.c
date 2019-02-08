/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:59:51 by llee              #+#    #+#             */
/*   Updated: 2019/01/23 12:00:13 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		error(char *msg)
{
	ft_putendl(msg);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = init_mlx();
	if (argc == 2)
	{
		if (read_input(mlx, argv[1]) == -1)
			error("invalid argv: ./fractol [mandelbrot/julia/bird]");
		else
			mlx_setup(mlx);
	}
	else
		error("invalid argc: ./fractol [mandelbrot/julia/bird]");
	return (0);
}

int		read_input(t_mlx *mlx, char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		mlx->get_set = mandelbrot_set;
	else if (ft_strcmp(str, "julia") == 0)
		mlx->get_set = julia_set;
	else if (ft_strcmp(str, "bird") == 0)
		mlx->get_set = bird_set;
	else
		return (-1);
	return (0);
}

void	mlx_setup(t_mlx *mlx)
{
	thread(mlx);
	mlx_key_hook(mlx->win_ptr, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_loop(mlx->mlx_ptr);
}
