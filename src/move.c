/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 17:33:53 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 22:04:05 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void		move_left_right(int key, t_key_hook *hook)
{
	float	diff;

	if (hook->fract_t == MANDEL)
	{
		diff = MAN_X_MAX * 0.25 * (1 / hook->zoom);
		diff *= (key == LEFT) ? -1 : 1;
		hook->x_min += diff;
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	else if (hook->fract_t == JULIA)
	{
		diff = JU_X_MAX * 0.25 * (1 / hook->zoom);
		diff *= (key == LEFT) ? -1 : 1;
		hook->x_min += diff;
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	}
	else
	{
		diff = BURN_X_MAX * 0.25 * (1 / hook->zoom);
		diff *= (key == LEFT) ? -1 : 1;
		hook->x_min += diff;
		thrd_ship(hook->iter_max, hook, hook->color_scheme);
	}
}

static void		move_up_down(int key, t_key_hook *hook)
{
	float	diff;

	if (hook->fract_t == MANDEL)
	{
		diff = MAN_Y_MAX * 0.25 * (1 / hook->zoom);
		diff *= (key == UP) ? -1 : 1;
		hook->y_min += diff;
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	else if (hook->fract_t == JULIA)
	{
		diff = JU_Y_MAX * 0.25 * (1 / hook->zoom);
		diff *= (key == UP) ? -1 : 1;
		hook->y_min += diff;
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	}
	else
	{
		diff = BURN_Y_MAX * 0.25 * (1 / hook->zoom);
		diff *= (key == UP) ? -1 : 1;
		hook->y_min += diff;
		thrd_ship(hook->iter_max, hook, hook->color_scheme);
	}
}

void			move(int key, t_key_hook *hook)
{
	if (key == UP || key == DOWN)
		move_up_down(key, hook);
	else if (key == LEFT || key == RIGHT)
		move_left_right(key, hook);
}
