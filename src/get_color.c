/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_color.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 16:06:52 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:53:20 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int color_scheme_gray(t_thrd_data data)
{
	if (data.iter_act < data.iter_max * 0.1)
		return (0x0);
	if (data.iter_act < data.iter_max * 0.17)
		return (_GRAY2);
	if (data.iter_act < data.iter_max * 0.25)
		return (_GRAY6);
	if (data.iter_act < data.iter_max * 0.33)
	 	return (_GRAY10);
	if (data.iter_act < data.iter_max * 0.41)
		return (_GRAY20);
	if (data.iter_act < data.iter_max * 0.5)
	 	return (_GRAY30);
	if (data.iter_act < data.iter_max * 0.58)
		return (_GRAY50);
	if (data.iter_act < data.iter_max * 0.66)
	 	return (_GRAY80);
	if (data.iter_act < data.iter_max * 0.75)
		return (_GRAY70);
	if (data.iter_act < data.iter_max * 0.91)
	 	return (_GRAY60);
	else
	 	return (0x000000);
}

static int color_scheme_earl(t_thrd_data data)
{
	if (data.iter_act < data.iter_max * 0.1)
		return (0x0);
	if (data.iter_act < data.iter_max * 0.17)
		return (_GRAY5);
	if (data.iter_act < data.iter_max * 0.25)
		return (_GRAY10);
	if (data.iter_act < data.iter_max * 0.33)
		return (_PURPLE);
	if (data.iter_act < data.iter_max * 0.41)
		return (_BLUE);
	if (data.iter_act < data.iter_max * 0.5)
		return (_GREEN);
	if (data.iter_act < data.iter_max * 0.58)
		return (_YELLOW);
	if (data.iter_act < data.iter_max * 0.66)
		return (_ORANGE);
	if (data.iter_act < data.iter_max * 0.75)
		return (_RED);
	if (data.iter_act < data.iter_max * 0.83)
		return (_PURPLE);
	if (data.iter_act < data.iter_max * 0.91)
		return (_BLUE);
	else
		return (_GREEN);
}


static int color_scheme_spyro(t_thrd_data data)
{
	if (data.iter_act < data.iter_max * 0.1)
		return (0x0);
	if (data.iter_act < data.iter_max * 0.17)
		return (_GRAY5);
	if (data.iter_act < data.iter_max * 0.25)
		return (_GRAY10);
	if (data.iter_act < data.iter_max * 0.33)
		return (_DARKORCHID4);
	if (data.iter_act < data.iter_max * 0.41)
		return (_DARKORCHID3);
	if (data.iter_act < data.iter_max * 0.5)
		return (_DARKORCHID2);
	if (data.iter_act < data.iter_max * 0.58)
		return (_ORCHID);
	if (data.iter_act < data.iter_max * 0.66)
		return (_DARKORCHID1);
	if (data.iter_act < data.iter_max * 0.75)
		return (_DARKORCHID2);
	if (data.iter_act < data.iter_max * 0.83)
		return (_PURPLE1);
	if (data.iter_act < data.iter_max * 0.91)
		return (_PURPLE2);
	else
		return (_DARKGOLDENROD3);
}

static int color_scheme_virgin(t_thrd_data data)
{

	if (data.iter_act < data.iter_max * 0.25)
		return (0x666666);
	if (data.iter_act < data.iter_max * 0.33)
		return (0x99aa99);
	if (data.iter_act < data.iter_max * 0.5)
		return (0x444444);
	if (data.iter_act < data.iter_max * 0.66)
		return (0x333333);
	if (data.iter_act < data.iter_max * 0.75)
		return (0x222222);
	if (data.iter_act < data.iter_max * 0.91)
		return (0x55ff55);
	else
		return (0x111111);
}

int get_color(t_thrd_data data)
{
	if (data.color_scheme == 1)
		return (color_scheme_gray(data));
	if (data.color_scheme == 2)
		return (color_scheme_virgin(data));
	if (data.color_scheme == 3)
		return (color_scheme_spyro(data));
	else
		return (color_scheme_earl(data));
}