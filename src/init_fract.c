/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_fract.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:58:10 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 22:11:34 by ccantin     ###    #+. /#+    ###.fr     */
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

static void		init_ship(t_key_hook *hook)
{
	hook->x_min = BURN_X_MIN;
	hook->y_min = BURN_Y_MIN;
	hook->x_max = BURN_X_MAX;
	hook->y_max = BURN_Y_MAX;
	hook->zoom = BURN_PX_HEIGHT;
	hook->mouse_x = 0;
	hook->mouse_y = 0;
}

void			init_fract(t_key_hook *hook)
{
	hook->iter_max = 30;
	if (hook->fract_t == MANDEL)
		init_mandel(hook);
	else if (hook->fract_t == JULIA)
		init_julia(hook);
	else
		init_ship(hook);
}

void			reset_fract(t_key_hook *hook)
{
	if (hook->fract_t == MANDEL)
	{
		init_fract(hook);
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	else if (hook->fract_t == JULIA)
	{
		init_fract(hook);
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	}
	else
	{
		init_fract(hook);
		thrd_ship(hook->iter_max, hook, hook->color_scheme);
	}
}
