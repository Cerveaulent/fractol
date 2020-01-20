/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_fract.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:58:10 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:24:34 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initialising all the variables need to calculate fractals
*/


static void		init_mandel(t_key_hook *hook)
{
	hook->x_min = MAN_X_MIN;
	hook->x_max = MAN_X_MAX;
	hook->y_min = MAN_Y_MIN;
	hook->y_max = MAN_Y_MAX;
	hook->zoom = MAN_PX_HEIGHT;
	hook->mouse_x = 0;
	hook->mouse_y = 0;
}
static void		init_julia(t_key_hook *hook)
{
	hook->x_min = JU_X_MIN;
	hook->y_min = JU_Y_MIN;
	hook->x_max = JU_X_MAX;
	hook->y_max = JU_Y_MAX;
	hook->zoom = JU_PX_HEIGHT;
	hook->mouse_x = 0;
	hook->mouse_y = 0;
}

void			init_fract(int fract_type, t_key_hook *hook)
{
	if (fract_type == MANDEL)
		init_mandel(hook);
	else if (fract_type == JULIA)
		init_julia(hook);
	else
	{
		hook->x_min = MAN_X_MIN;
		hook->x_max = MAN_X_MAX;
		hook->y_min = MAN_Y_MIN;
		hook->y_max = MAN_Y_MAX;
		hook->zoom = MAN_PX_HEIGHT;
	}
	hook->iter_max = 30;
}

void		reset_fract(t_key_hook *hook)
{
	if (hook->fract_t == MANDEL)
	{
		init_fract(hook->fract_t, hook);
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	else if (hook->fract_t == JULIA)
	{
		init_fract(hook->fract_t, hook);
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	}
	// else
	// {
	// 	hook->x_min = JU_X_MIN;
	// 	hook->y_min = JU_Y_MIN;
	// 	hook->x_max = JU_X_MAX;
	// 	hook->y_max = JU_Y_MAX;
	// }
}
