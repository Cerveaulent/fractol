/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_handler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 19:11:55 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 20:52:06 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	free_rdr(t_renderer *rdr)
{
	free(rdr);
	rdr = NULL;
}

void	free_mlx(t_mlx *mlx)
{
	free(mlx);
	mlx = NULL;
}

void	free_hook(t_key_hook *hook)
{
	free_rdr(hook->rdr);
	free_mlx(hook->mlx);
	free(hook);
	hook = NULL;
}