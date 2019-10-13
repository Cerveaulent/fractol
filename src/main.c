/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:25:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 16:55:04 by charles     ###    #+. /#+    ###.fr     */
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
	double i;
	double calc;

	calc = 0.0;
	i = 0.0;
	a.x = W_WIDTH/2;
	a.y = W_HEIGHT/2;
	a.color = 0xff00ff;

	mlx = init_mlx();
	rdr = init_rdr(mlx, W_WIDTH, W_HEIGHT);
	while (i < 150)
	{
		calc = pow(i,2);
		put_pixel(a,rdr);
		a.x += 1;
		if (calc >= 0)
			a.y -= round ((1000*calc));
		else
			a.y += 10 + calc;
		i += 0.001;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, rdr->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, key_pressed, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
