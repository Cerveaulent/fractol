/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom_handler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 14:07:08 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 19:51:50 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void			zoom_in(int x, int y, t_key_hook *hook)
{
	float	tmp_zoom;

	tmp_zoom = hook->zoom * ZOOM;
	hook->x_min = (x / hook->zoom + hook->x_min) - (x / tmp_zoom);
	hook->x_max = (x / hook->zoom + hook->x_max) - (x / tmp_zoom);
	hook->y_min = (y / hook->zoom + hook->y_min) - (y / tmp_zoom);
	hook->y_max = (y / hook->zoom + hook->y_max) - (y / tmp_zoom);
	hook->zoom = tmp_zoom;
	if (hook->iter_max <= 1000)
		hook->iter_max++;
}

static void			zoom_out(int x, int y, t_key_hook *hook)
{
	float	tmp_zoom;

	tmp_zoom = hook->zoom / ZOOM;
	hook->x_min = (x / hook->zoom + hook->x_min) - (x / tmp_zoom);
	hook->x_max = (x / hook->zoom + hook->x_max) - (x / tmp_zoom);
	hook->y_min = (y / hook->zoom + hook->y_min) - (y / tmp_zoom);
	hook->y_max = (y / hook->zoom + hook->y_max) - (y / tmp_zoom);
	hook->zoom = tmp_zoom;
	if (hook->iter_max > 1)
		hook->iter_max--;
}

void			zoom(int key, int x, int y, t_key_hook *hook)
{
	if (key == SCROLL_UP)
	{
		zoom_in(x, y, hook);
		if (hook->fract_t == 1)
			thrd_mandel(hook->iter_max, hook, hook->color_scheme);
		else if (hook->fract_t == 2)
			return ;
		else
			return ;
	}
	else
	{
		zoom_out(x, y, hook);
		if (hook->fract_t == 1)
			thrd_mandel(hook->iter_max, hook, hook->color_scheme);
		else if (hook->fract_t == 2)
			return ;
		else
			return ;
	}
}