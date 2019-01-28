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

int	error(char *msg)
{
	ft_putendl(msg);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 2)
	{
		if (read_input(argv[1]) == -1)
			error("invalid argv: ./fractol [mandelbrot/julia]");
		mlx_setup(&mlx);
	}
	else
		error("invalid argc: ./fractol [mandelbrot/julia]");
	return (0);
}

int	read_input(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		printf("execute mandelbrot set\n");
	else if (ft_strcmp(str, "julia") == 0)
		printf("execute julia set\n");
	else
		return (-1);
	return (0);
}

void	mlx_setup(t_mlx **mlx)
{
	(*mlx) = init_mlx();
	mlx_key_hook((*mlx)->win_ptr, hook_keydown, mlx);
	mlx_loop((*mlx)->mlx_ptr);
}