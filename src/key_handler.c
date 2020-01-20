/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_handler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:47:13 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 17:34:09 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void		change_color(t_key_hook *hook)
{
	if (hook->color_scheme <= 3)
		hook->color_scheme++;
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

