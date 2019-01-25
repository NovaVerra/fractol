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
	if (argc == 2)
	{
		if (read_input(argv[1]) == -1)
			error("invalid command: ./fractol [madelbort/julia/burningship]");
	}
	else
		error("insufficient argument: ./fractol [madelbort/julia/burningship]");
	return (0);
}

int	read_input(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		printf("execute mandelbrot set");
	else if (ft_strcmp(str, "julia") == 0)
		printf("execute julia set");
	else if (ft_strcmp(str, "burningship") == 0)
		printf("execute burningship set");
	else
		return (-1);
	return (0);
}
