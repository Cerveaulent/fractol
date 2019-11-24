/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:25:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 10:31:21 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_mlx	*mlx;
	t_renderer *rdr;
	t_pts a;
	t_pts x; t_pts y;
	t_pts p, l;
	double i;
	double calc;

	x.x = 0;
	x.y = W_HEIGHT/2;
	x.color = 0xffff00;
	y.x = W_WIDTH;
	y.y = W_HEIGHT/2;
	y.color = 0xffff00;
	p.x = W_WIDTH/2;
	p.y = 0;
	p.color = 0xffff00;
	l.x = W_WIDTH/2;
	l.y = W_HEIGHT;
	l.color = 0xffff00;
	calc = 0.0;
	i = 0.0;
	a.x = W_WIDTH/2;
	a.y = W_HEIGHT/2;
	a.color = 0xff00ff;

	mlx = init_mlx();
	rdr = init_rdr(mlx, W_WIDTH, W_HEIGHT);
	calc_mandel(rdr, 10000);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, rdr->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, key_pressed, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
