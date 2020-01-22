/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_julia.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 12:02:51 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 17:51:46 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_pressed(int key, int x, int y, t_key_hook *hook)
{
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		zoom(key, x, y, hook);
	else if (key == M_LCLICK && hook->ju_move == 1 && hook->fract_t == 2)
		hook->ju_move = 0;
	else if (key == M_LCLICK && hook->ju_move == 0 && hook->fract_t == 2)
		hook->ju_move = 1;
	return (1);
}

int			update_julia(int x, int y, t_key_hook *hook)
{
	if (hook->ju_move == 1 && hook->fract_t == 2)
	{
		hook->mouse_x = x;
		hook->mouse_y = y;
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
		return (0);	 
	}
	else 
		return (0);
}