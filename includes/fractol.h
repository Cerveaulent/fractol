/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:47:45 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 15:47:07 by ccantin     ###    #+. /#+    ###.fr     */
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
# define W_HEIGHT 1080
# define W_WIDTH 1900
# define L_OFFSET 300
# define TOP_OFFSET 200

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
	double			x;
	double			y;
	double			color;

}					t_pts;

typedef struct 		s_complex
{
	int				real;
	int				imagi;
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

typedef struct		s_err_bres
{
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	double			err;
	double			e2;
}					t_err_bres;

t_mlx				*init_mlx(void);
int					key_pressed(int key, t_mlx *mlx);
t_renderer			*init_rdr(t_mlx *mlx, int width, int height);
void				main_bresenham(t_pts p_a, t_pts p_b, t_renderer *rdr);
void				put_pixel(t_pts a, t_renderer *rdr);
#endif
