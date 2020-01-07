/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_handler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:47:13 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 19:10:28 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
/*
** this function needs to move
*/

static void		reset_fract(t_key_hook *hook)
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

static void		move(int key, t_key_hook *hook)
{
	float	diff;

	if (key == UP || key == DOWN)
	{
		if (hook->fract_t == MANDEL)
		{
			diff = (key == UP) ? (-(MAN_Y_MAX * 0.25 * (1/hook->zoom))) : (MAN_Y_MAX * 0.25 * (1/hook->zoom));
			hook->y_min += diff;
			thrd_mandel(hook->iter_max, hook, hook->color_scheme);
		}
		// else if (hook->fract_t == JULIA)
		// 	diff = (key == UP) ? -(MAN_Y_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
		// else
		// 	diff = (key == UP) ? -(MAN_Y_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
	}
	else if (key == LEFT || key == RIGHT)
	{
		if (hook->fract_t == MANDEL)
		{
			diff = (key == LEFT) ? (-(MAN_X_MAX * 0.25 * (1/hook->zoom))) : (MAN_X_MAX * 0.25 * (1/hook->zoom));
			hook->x_min += diff;
			thrd_mandel(hook->iter_max, hook, hook->color_scheme);
		}
		// else if (hook->fract_t == JULIA)
		// 	diff = (key == LEFT) ? -(MAN_Y_MAX * 0.0625) : (MAN_X_MAX * 0.0625);
		// else
		// 	diff = (key == LEFT) ? -(MAN_X_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
	}
	
}

static void		change_color(t_key_hook *hook)
{
	if (hook->color_scheme <= 3)
	{
		hook->color_scheme++;
	}
	else
		hook->color_scheme = 1;
	if (hook->fract_t == MANDEL)
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	else if (hook->fract_t == JULIA)
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
}

static void		change_iter(int key, t_key_hook *hook)
{
	if (key == U && hook->iter_max < 1000)
		hook->iter_max++;
	else if (key == Y && hook->iter_max < 990)
		hook->iter_max += 10;
	else if (key == I && hook->iter_max > 1)
		hook->iter_max--;
	else if (key == O && hook->iter_max > 10)
		hook->iter_max -= 10;
	if (hook->fract_t == 1)
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	else if (hook->fract_t == 2)
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	else
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
}

int		key_pressed(int key, t_key_hook *hook)
{
	if (key == ESC)
	{
		free_hook(hook);
		exit(EXIT_SUCCESS);
	}
	else if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		move(key, hook);
	else if (key == R)
		reset_fract(hook);
	else if (key == U || key == I || key == O || key == Y)
		change_iter(key, hook);
	else if (key == C)
		change_color(hook);
	return(0);
}

int		mouse_pressed(int key, int x, int y, t_key_hook *hook)
{
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		zoom(key, x, y, hook);
	return (1);
}
