/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 17:33:53 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 17:35:01 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void		move_left_right(int key, t_key_hook *hook)
{
	float	diff;

	if (hook->fract_t == MANDEL)
	{
		diff = (key == LEFT) ? (-(MAN_X_MAX * 0.25 * (1/hook->zoom)))
		: (MAN_X_MAX * 0.25 * (1/hook->zoom));
		hook->x_min += diff;
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	else if (hook->fract_t == JULIA)
	{
		diff = (key == LEFT) ? (-(JU_X_MAX * 0.25 * (1/hook->zoom)))
		: (JU_X_MAX * 0.25 * (1/hook->zoom));
		hook->x_min += diff;
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	}
	// else
	// 	diff = (key == LEFT) ? -(MAN_X_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
}


static void		move_up_down(int key, t_key_hook *hook)
{
	float	diff;

	if (hook->fract_t == MANDEL)
	{
		diff = (key == UP) ? (-(MAN_Y_MAX * 0.25 * (1/hook->zoom))) \
			: (MAN_Y_MAX * 0.25 * (1/hook->zoom));
		hook->y_min += diff;
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	else if (hook->fract_t == JULIA)
	{
		diff = (key == UP) ? (-(JU_Y_MAX * 0.25 * (1/hook->zoom))) \
			: (JU_Y_MAX * 0.25 * (1/hook->zoom));
		hook->y_min += diff;
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	}
	// else
	// 	diff = (key == UP) ? -(MAN_Y_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
}

void		move(int key, t_key_hook *hook)
{

	if (key == UP || key == DOWN)
		move_up_down(key, hook);
	else if (key == LEFT || key == RIGHT)
		move_left_right(key, hook);
	
}