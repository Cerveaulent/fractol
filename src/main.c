/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:25:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:55:40 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	t_key_hook	*k_hook;

	k_hook = init_hook(1);
	thrd_mandel(20, k_hook, 3);
	mlx_hook(k_hook->mlx->win_ptr, 2, (1L << 17), key_pressed, k_hook);
	mlx_hook(k_hook->mlx->win_ptr, 4, (1L << 6), mouse_pressed, k_hook);
	mlx_hook(k_hook->mlx->win_ptr, 6, (1L << 6), NULL, k_hook);
	mlx_loop(k_hook->mlx->mlx_ptr);
	return (0);
}
