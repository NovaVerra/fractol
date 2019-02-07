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
# include <limits.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MAX_THREAD 5

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
int				read_input(t_mlx **mlx, char *str);
void			mlx_setup(t_mlx *mlx);

// init.c
t_mlx			*init_mlx(void);
t_image			*init_image(t_mlx *mlx);

// clean.c
t_mlx			*clean_mlx(t_mlx *mlx);
t_image			*clean_image(t_mlx *mlx, t_image *image);
void			reset_image(t_image *image);

// render.c
void			thread(t_mlx *mlx);
void			*render(void *arg);
void			img_put_pixel(t_image *img, int x, int y, int color);

// input.c
int				key_press(int keycode, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_release(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);

// input2.c
void			change_set(t_mlx *mlx, int keycode);
void			shift_cam(t_mlx *mlx, int keycode);
void			iterate_set(t_mlx *mlx, int keycode);
void			zoom_cam(t_mlx *mlx, int keycode);
void			reset(t_mlx *mlx);

// color.c
void			get_color(int i, t_thread *thrd, int x, int y);
void			message(t_mlx *mlx);
void			message_2(t_mlx *mlx);

// set.c
int				julia_set();
int				mandelbrot_set();
int				burningship_set();
t_set			calc_cam(int x, int y, t_thread *set);

#endif
