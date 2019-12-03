/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_handler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:47:13 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 17:03:01 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"
/*
** this function needs to move
*/
int check_modif(t_key_hook *k_hook, t_thrd_data *data)
{
	if (k_hook->x_min != MAN_X_MIN || k_hook->y_min != MAN_Y_MIN)
	{
		data->x_min = k_hook->x_min;
		data->y_min = k_hook->y_min;
	}
	else
	{
		data->x_min = MAN_X_MIN;
		data->y_min = MAN_Y_MIN;
	}
	return (1);
}

static void		reset_fract(t_key_hook *hook)
{
	hook->iter_max = 50;
	if (hook->fract_t == MANDEL)
	{
		hook->x_min = MAN_X_MIN;
		hook->y_min = MAN_Y_MIN;
		hook->x_max = MAN_X_MAX;
		hook->y_max = MAN_Y_MAX;
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	// else if (hook->fract_t == JULIA)
	// {
	// 	hook->x_min = JU_X_MIN;
	// 	hook->y_min = JU_Y_MIN;
	// 	hook->x_max = JU_X_MAX;
	// 	hook->y_max = JU_Y_MAX;
	// }
	// else
	// {
	// 	hook->x_min = JU_X_MIN;
	// 	hook->y_min = JU_Y_MIN;
	// 	hook->x_max = JU_X_MAX;
	// 	hook->y_max = JU_Y_MAX;
	// }
}

static void		move(int key, t_key_hook *k_hook)
{
	float	diff;

	if (key == UP || key == DOWN)
	{
		if (k_hook->fract_t == MANDEL)
		{
			diff = (key == UP) ? (-(MAN_Y_MAX * 0.0625)) : (MAN_Y_MAX * 0.0625);
			k_hook->y_min += diff;
			thrd_mandel(k_hook->iter_max, k_hook, k_hook->color_scheme);
		}
		// else if (k_hook->fract_t == JULIA)
		// 	diff = (key == UP) ? -(MAN_Y_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
		// else
		// 	diff = (key == UP) ? -(MAN_Y_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
	}
	else if (key == LEFT || key == RIGHT)
	{
		if (k_hook->fract_t == MANDEL)
		{
			diff = (key == LEFT) ? (-(MAN_X_MAX * 0.0625)) : (MAN_X_MAX * 0.0625);
			k_hook->x_min += diff;
			thrd_mandel(k_hook->iter_max, k_hook, k_hook->color_scheme);
		}
		// else if (k_hook->fract_t == JULIA)
		// 	diff = (key == LEFT) ? -(MAN_Y_MAX * 0.0625) : (MAN_X_MAX * 0.0625);
		// else
		// 	diff = (key == LEFT) ? -(MAN_X_MAX * 0.0625) : (MAN_Y_MAX * 0.0625);
	}
	
}

static void			zoom(int key, t_key_hook *hook)
{
	(void)hook;
	if (key == SCROLL_UP)
	{
		hook->x_min *= MAN_PX_HEIGHT;
		hook->y_max *= MAN_PX_HEIGHT;
		hook->y_min *= MAN_PX_HEIGHT;
		hook->x_max *= MAN_PX_HEIGHT;
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	return ;
}


int		key_pressed(int key, t_key_hook *k_hook)
{
	if (key == ESC)
	{
		free(k_hook->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		move(key, k_hook);
	else if (key == R)
		reset_fract(k_hook);
	return(0);
}

int		mouse_pressed(int key, t_key_hook *m_hook)
{
	(void)key;
	(void)m_hook;
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		zoom(key, m_hook);    
	return (1);
}
