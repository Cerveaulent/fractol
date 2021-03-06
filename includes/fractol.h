/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:47:45 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 22:14:04 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <math.h>
# include "mlx.h"
# include "colors.h"
# include "key_map.h"
# include "mouse_map.h"
# include <pthread.h>
# include <stdio.h>

/*
** --------------------GENERAL MACROS-------------- **
*/
# define ITER_MAX 1000
# define ZOOM 1.1

/*
** --------------------UI_MACROS------------------- **
*/
# define W_HEIGHT 1080
# define W_WIDTH 1900
# define L_OFFSET 300
# define TOP_OFFSET 200

/*
** --------------------MANDEL_MACROS------------------- **
*/
# define MANDEL 1
# define MAN_X_MIN -2.6
# define MAN_X_MAX 2.2
# define MAN_Y_MIN -1.2
# define MAN_Y_MAX 2.4
# define MAN_PX_HEIGHT 450

/*
** --------------------JULIA_MACROS------------------- **
*/
# define JULIA 2
# define JU_X_MIN -2.6
# define JU_X_MAX 3
# define JU_Y_MIN -1.6
# define JU_Y_MAX 3
# define JU_PX_HEIGHT 360

/*
** --------------------BURNING_MACROS------------------- **
*/
# define BURNING 3
# define BURN_X_MIN -2.6
# define BURN_X_MAX 2.2
# define BURN_Y_MIN -1.2
# define BURN_Y_MAX 2.4
# define BURN_PX_HEIGHT 450

/*
** --------------------STRUCTURES------------------- **
*/

typedef struct		s_mlx
{
	void			*win_ptr;
	void			*mlx_ptr;
}					t_mlx;

typedef struct		s_fimg
{
	int				bpp;
	int				size_l;
	int				endian;
}					t_fimg;

typedef struct		s_pts
{
	float			x;
	float			y;
	float			color;

}					t_pts;

typedef struct		s_complex
{
	float			real;
	float			imagi;
}					t_complex;

typedef struct		s_renderer
{
	int				r_wid;
	int				r_hei;
	int				r_size;
	void			*img_ptr;
	unsigned int	*data;
	t_fimg			img;

}					t_renderer;

typedef struct		s_thrd_data
{
	int				iter_act;
	int				iter_max;
	int				thrd_nb;
	float			x_min;
	float			y_min;
	float			x_max;
	float			y_max;
	int				mouse_x;
	int				mouse_y;
	int				ju_move;
	float			zoom;
	t_complex		zn;
	t_complex		c;
	t_renderer		*rdr;
	int				color_scheme;
}					t_thrd_data;

typedef struct		s_key_hook
{
	t_renderer		*rdr;
	t_mlx			*mlx;
	int				iter_max;
	int				fract_t;
	float			x_min;
	float			y_min;
	float			x_max;
	float			y_max;
	float			zoom;
	int				mouse_x;
	int				mouse_y;
	int				ju_move;
	int				color_scheme;
}					t_key_hook;

typedef struct		s_err_bres
{
	float			dx;
	float			dy;
	float			sx;
	float			sy;
	float			err;
	float			e2;
}					t_err_bres;

/*
** --------------------INIT------------------- **
*/
void				init_fract(t_key_hook *hook);
t_key_hook			*init_hook(int fract_t);
t_mlx				*init_mlx(void);
t_renderer			*init_rdr(t_mlx *mlx, int width, int height);
void				reset_fract(t_key_hook *hook);

/*
** --------------------EVENTS------------------- **
*/
int					key_pressed(int key, t_key_hook *k_hook);
int					mouse_pressed(int key, int x, int y, t_key_hook *m_hook);
void				move(int key, t_key_hook *hook);
int					update_julia(int x, int y, t_key_hook *hook);
int					quit(t_key_hook *hook);
void				zoom(int key, int x, int y, t_key_hook *hook);

/*
** --------------------UTILS------------------- **
*/
int					get_color(t_thrd_data data);
void				main_bresenham(t_pts p_a, t_pts p_b, t_renderer *rdr);
void				put_pixel(t_pts a, t_renderer *rdr);

/*
** --------------------CALC------------------- **
*/
t_complex			complex_add(t_complex a, t_complex b);
float				complex_mod(t_complex com);
t_complex			complex_mul(t_complex a, t_complex b);
int					thrd_julia(int iter_max, t_key_hook *hook, int color_sch);
int					thrd_mandel(int iter_max, t_key_hook *hook, int color_sch);
int					thrd_ship(int iter_max, t_key_hook *hook, int color_scheme);

/*
** --------------------FREE------------------- **
*/
void				free_hook(t_key_hook *hook);
#endif
