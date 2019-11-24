/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandel_bro.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 14:16:40 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 10:27:54 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"


int calc_mandel(t_renderer *rdr, int iter_max)
{
	t_pts		tmp_pts;
	t_complex	zn;
	t_complex	c;
	int 		iter_act;


	tmp_pts.y = 0;
	while((int)tmp_pts.y <= rdr->r_hei)
	{
		tmp_pts.x = 0;
		while((int)tmp_pts.x <= rdr->r_wid)
		{
			zn.real = 0;
			zn.imagi = 0;
			c.real = tmp_pts.x / MAN_ZOOM + MAN_X_MIN;
			c.imagi = tmp_pts.y / MAN_ZOOM + MAN_Y_MIN;
			iter_act = 0;
			while (iter_max > iter_act)
			{
				zn = complex_add(complex_mul(zn,zn), c);
				if (complex_mod(zn) >= 4)
				{
					tmp_pts.color = 0x0;
					break;
				}
				iter_act++;	
			}				
			if (iter_act == iter_max)
				tmp_pts.color = 0xff00ff;
			put_pixel(tmp_pts, rdr);
			tmp_pts.x += 1;
		}
		tmp_pts.y += 1;
	}
	return (1);
}