/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandel_bro.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 14:16:40 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 18:37:35 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int rec_mandel(int iter_max, int *iter_act, t_complex *calc)
{
	int sq_mod;

	sq_mod = calc.real * calc.real + calc.imagi * calc.imagi;
	if (iter_act < iter_max && sq_mod > 4)
		return (0);
	if (iter_act == iter_max && sq_mod <= 4)
		return (1);
	if (iter_act < iter_max)
		return (rec_mandel(iter_max, (*iter_act)++, calc))

}

int calc_mandel(t_renderer *rdr, int iter_max)
{
	t_pts tmp_pts;
	int iter_max;
	t_complex tmp_com;

	iter_max = 0;
	while((int)tmp_pts.y <= rdr->r_hei)
	{
		(int)tmp_pts.x = 0;
		while((int)tmp_pts.x <= rdr->r_wid)
		{
			if (rec_mandel(iter_max, &iter_max, &tmp_com))
				tmp_pts.color = 0xffffff;
			else
				tmp_pts.color = 0x000000;
			put_pixel(tmp_pt,rdr);
			tmp_pts.x += 1;
		}
		tmp_pts.y += 1;
		tmp_com.imagi = (int)tmp_pts.y;
	}
	return (1);
}