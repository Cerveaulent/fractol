/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 21:19:22 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:59:46 by charles     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_pts a, t_renderer *rdr)
{
	if (a.x < rdr->r_wid && a.y < rdr->r_hei && a.x > 0 
			&& a.y > 0 &&
			(int)(a.y * rdr->r_wid + a.x) < rdr->r_wid * rdr->r_hei)
				rdr->data[(int)(a.y * rdr->r_wid + a.x)] = a.color;
}

static void	init_bres(t_pts p_a, t_pts p_b, t_err_bres *bres)
{
	bres->dx = fabs(p_b.x - p_a.x);
	bres->dy = fabs(p_b.y - p_a.y);
	bres->sx = p_a.x < p_b.x ? 1 : -1;
	bres->sy = p_a.y < p_b.y ? 1 : -1;
	bres->err = (bres->dx > bres->dy ? bres->dx : -bres->dy) / 2;
}

void		main_bresenham(t_pts p_a, t_pts p_b, t_renderer *rdr)
{ 
	t_err_bres	bres;

	init_bres(p_a, p_b, &bres);
	while (1)
	{
		if (p_a.x < rdr->r_wid && p_a.y < rdr->r_hei && p_a.x > 0 
			&& p_a.y > 0 &&
			(int)(p_a.y * rdr->r_wid + p_a.x) < rdr->r_wid * rdr->r_hei)
				put_pixel(p_a, rdr);
		if (p_a.x == p_b.x && p_a.y == p_b.y) 
			break;
		bres.e2 = bres.err;
		if (bres.e2 >- bres.dx)
			{
				bres.err -= bres.dy;
				p_a.x += bres.sx;
			}
		if (bres.e2 < bres.dy)
		{
				bres.err += bres.dx;
				p_a.y += bres.sy;
		}
  	}
}
