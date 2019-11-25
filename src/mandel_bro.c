/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandel_bro.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 14:16:40 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 21:10:06 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
#include "colors.h"

/*
** Initialising data needed to multithread process the fractal calculus
*/

static void	init_thrd_data(double x, double y, t_thrd_data *data, int iter_max)
{
	data->zn.real = 0;
	data->zn.imagi = 0;
	data->c.real = x / MAN_ZOOM + MAN_X_MIN;
	data->c.imagi = y / MAN_ZOOM + MAN_Y_MIN;
	data->iter_max = iter_max;
	data->iter_act = 0;
}

static int	rec_calc_mandel(t_thrd_data *data)
{
	data->zn = complex_add(complex_mul(data->zn,data->zn), data->c);
	if (data->iter_max > data->iter_act && ((data->zn.real * data->zn.real +
		data->zn.imagi * data->zn.imagi) < 4))
	{
		data->iter_act += 1;
		return (rec_calc_mandel(data));
	}
	else if (data->iter_max == data->iter_act)
		return (0);
	else
		return (1);
}

/*
** need to change with color scheme implementation
*/

static void	*calc_mandel(void *data)
{
	t_pts		tmp_pts;
	t_thrd_data *tmp_data;

	tmp_data = (t_thrd_data *)data;
	tmp_pts.y = tmp_data->rdr->r_hei * (tmp_data->thrd_nb) / 4;
	while((int)tmp_pts.y < (tmp_data->rdr->r_hei * (tmp_data->thrd_nb + 1)) / 4)
	{
		tmp_pts.x = 0;
		while((int)tmp_pts.x <= tmp_data->rdr->r_wid)
		{
			init_thrd_data(tmp_pts.x, tmp_pts.y, tmp_data, tmp_data->iter_max);
			if (rec_calc_mandel(tmp_data))
				tmp_pts.color = _BLUE_THREE;
			else
				tmp_pts.color = _YELLOW_THREE;
			put_pixel(tmp_pts, tmp_data->rdr);
			tmp_pts.x += 1;
		}
		tmp_pts.y += 1;
	}
	free(data);
	pthread_exit(NULL);
}

int		thrd_mandel(int iter_max, t_renderer *rdr)
{
	int i;
	t_thrd_data *data;
	pthread_t	thrd_tab[4];

	i = -1;
	data = NULL;
	while (++i < 4)
	{
		data = malloc(sizeof(t_thrd_data));
		data->thrd_nb = i;
		init_thrd_data(0, 0, data, iter_max);
		data->rdr = rdr;
		pthread_create(&thrd_tab[i], NULL, calc_mandel, data);
	}
	i = -1;
	while (++i < 4)
		pthread_join(thrd_tab[i], NULL);
	return (0);
}