/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:25:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 19:18:07 by ccantin     ###    #+. /#+    ###.fr     */
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

	mlx = init_mlx();
	rdr = init_rdr(mlx, W_WIDTH, W_HEIGHT);
	thrd_mandel(100, rdr, 4);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, rdr->img_ptr, 0, 0);
	mlx_key_hook(mlx->win_ptr, key_pressed, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
