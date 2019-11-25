/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_functions.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:26:59 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 18:11:25 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initialising all the pointers by the mlx functions
** They are stored in a structure define in fdf.h
*/

t_mlx			*init_mlx(void)
{
	t_mlx	*mlx_struct;

	mlx_struct = NULL;
	if (!(mlx_struct = malloc(sizeof(t_mlx))))
		return (NULL);
	mlx_struct->mlx_ptr = mlx_init();
	mlx_struct->win_ptr = mlx_new_window(mlx_struct->mlx_ptr, W_WIDTH, W_HEIGHT,
		"fdf");
	return (mlx_struct);
}

/*
** Initialising renderer to make easier display and have better
** perfs
*/

t_renderer		*init_rdr(t_mlx *mlx, int width, int height)
{
	t_renderer	*rdr;

	rdr = NULL;
	if (mlx == NULL)
		return (NULL);
	if (!(rdr = malloc(sizeof(t_renderer))))
		return (NULL);
	rdr->r_wid = width;
	rdr->r_hei = height;
	rdr->r_size = width * height;
	rdr->img.size_l = 0;
	rdr->img.bpp = 0;
	rdr->img.endian = 0;
	rdr->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	rdr->data = (unsigned int *)mlx_get_data_addr(rdr->img_ptr, &rdr->img.bpp,
		&rdr->img.size_l, &rdr->img.endian);
	return (rdr);
}
