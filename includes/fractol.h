/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:57:52 by llee              #+#    #+#             */
/*   Updated: 2019/01/23 11:59:43 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define THREAD_COUNT 8

typedef struct	s_thread
				t_thread;

typedef struct	s_set
{
	double		r;
	double		i;
	double		r_2;
	double		i_2;
}				t_set;

typedef struct	s_mouse
{
	int			pressed;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct	s_image
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			line;
	int			endian;
}				t_image;

typedef struct	s_cam
{
	double		x;
	double		y;
	double		offset_x;
	double		offset_y;
	double		zoom;
}				t_cam;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			max_iteration;
	int			color;
	int			(*get_set)(int, int, t_thread*);
	t_set		*set;
	t_cam		*cam;
	t_image		*image;
	t_mouse		*mouse;
}				t_mlx;

typedef struct	s_thread
{
	int			id;
	t_mlx		*mlx;
}				t_thread;

// main.c
int				error(char *msg);
int				read_input(char *str);
void			mlx_setup(t_mlx **mlx);

// init.c
t_mlx			*init_mlx(void);
t_image			*init_image(t_mlx *mlx);

// clean.c
t_mlx			*clean_mlx(t_mlx *mlx);
t_image			*clean_image(t_mlx *mlx, t_image *image);
void			reset_image(t_image *image);

// input.c
int				hook_keydown(int keycode, t_mlx *mlx);

#endif
