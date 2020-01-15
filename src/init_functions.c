/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_functions.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:26:59 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 19:49:08 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initialising all the variables need to calculate fractals
*/

void			init_fract(int fract_type, t_key_hook *hook)
{
	if (fract_type == MANDEL)
	{
		hook->x_min = MAN_X_MIN;
		hook->x_max = MAN_X_MAX;
		hook->y_min = MAN_Y_MIN;
		hook->y_max = MAN_Y_MAX;
		hook->zoom = MAN_PX_HEIGHT;
	}
	else if (fract_type == JULIA)
	{
		hook->x_min = JU_X_MIN;
		hook->y_min = JU_Y_MIN;
		hook->x_max = JU_X_MAX;
		hook->y_max = JU_Y_MAX;
		hook->zoom = JU_PX_HEIGHT;
	}
	else
	{
		hook->x_min = MAN_X_MIN;
		hook->x_max = MAN_X_MAX;
		hook->y_min = MAN_Y_MIN;
		hook->y_max = MAN_Y_MAX;
		hook->zoom = MAN_PX_HEIGHT;
	}
	hook->iter_max = 20;
}

/*
** Initialising all the pointers by the mlx functions
** They are stored in a structure define in fdf.h
*/

t_mlx			*init_mlx(void)
{
	t_mlx	*mlx_struct;

	mlx_struct = NULL;
	if (!(mlx_struct = malloc(sizeof(t_mlx))))
		return (NULL);
	mlx_struct->mlx_ptr = mlx_init();
	mlx_struct->win_ptr = mlx_new_window(mlx_struct->mlx_ptr, W_WIDTH, W_HEIGHT,
		"fdf");
	return (mlx_struct);
}

/*
** Initialising renderer to make easier display and have better
** perfs
*/

t_renderer		*init_rdr(t_mlx *mlx, int width, int height)
{
	t_renderer	*rdr;

	rdr = NULL;
	if (mlx == NULL)
		return (NULL);
	if (!(rdr = malloc(sizeof(t_renderer))))
		return (NULL);
	rdr->r_wid = width;
	rdr->r_hei = height;
	rdr->r_size = width * height;
	rdr->img.size_l = 0;
	rdr->img.bpp = 0;
	rdr->img.endian = 0;
	rdr->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	rdr->data = (unsigned int *)mlx_get_data_addr(rdr->img_ptr, &rdr->img.bpp,
		&rdr->img.size_l, &rdr->img.endian);
	return (rdr);
}

/*
** Initialising Hook for events handling
*/

t_key_hook		*init_hook(int fract_t)
{
	t_key_hook	*hook;
	
	if (!(hook = malloc(sizeof(t_key_hook))))
		return (NULL);
	hook->mlx = init_mlx();
	hook->rdr = init_rdr(hook->mlx, W_WIDTH, W_HEIGHT);
	hook->fract_t = fract_t;
	hook->zoom = 1.1;
	hook->ju_move = 0;
	init_fract(fract_t, hook);
	return (hook);
}