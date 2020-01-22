/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ship_cuzin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 19:03:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 21:15:53 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int	check_modif(t_key_hook *hook, t_thrd_data *data)
{
	if (hook->x_min != BURN_X_MIN || hook->y_min != BURN_Y_MIN \
		|| hook->zoom != data->zoom)
	{
		data->x_min = hook->x_min;
		data->y_min = hook->y_min;
		data->zoom = hook->zoom;
	}
	else
	{
		data->x_min = BURN_X_MIN;
		data->y_min = BURN_Y_MIN;
		data->zoom = BURN_PX_HEIGHT;
	}
	return (1);
}

/*
** Initialising data needed to multithread process the fractal calculus
*/

static void	init_thrd_data(double x, double y, t_thrd_data *data, int iter_max)
{
	data->zn.real = 0;
	data->zn.imagi = 0;
	data->c.real = x / data->zoom + data->x_min;
	data->c.imagi = y / data->zoom + data->y_min;
	data->iter_max = iter_max;
	data->iter_act = 0;
}

/*
** Recursive implementation of Burning set
*/

static int	rec_calc_ship(t_thrd_data *data)
{
	data->zn.real = fabs(data->zn.real);
	data->zn.imagi = fabs(data->zn.imagi);
	data->zn = complex_add(complex_mul(data->zn, data->zn), data->c);
	if (data->iter_max > data->iter_act && ((data->zn.real * data->zn.real +
		data->zn.imagi * data->zn.imagi) < 4))
	{
		data->iter_act += 1;
		return (rec_calc_ship(data));
	}
	else
		return (0);
}

/*
** Slightly optimised thread exectution to color each pixel
*/

static void	*calc_ship(void *data)
{
	t_pts		pt;
	t_thrd_data *tmp;
	float		p;

	p = (pt.x - 0.25) * (pt.x - 0.25) + (pt.y * pt.y);
	tmp = (t_thrd_data *)data;
	pt.y = tmp->rdr->r_hei * (tmp->thrd_nb) * 0.25;
	while (pt.y < (tmp->rdr->r_hei * (tmp->thrd_nb + 1)) * 0.25)
	{
		pt.x = 0;
		while ((int)pt.x < tmp->rdr->r_wid)
		{
			init_thrd_data(pt.x, pt.y, tmp, tmp->iter_max);
			rec_calc_ship(tmp);
			pt.color = get_color(*tmp);
			put_pixel(pt, tmp->rdr);
			pt.x += 1;
		}
		pt.y += 1;
	}
	free(tmp);
	data = NULL;
	pthread_exit(NULL);
}

/*
** Creation of threads that calculate Burning ship set
*/

int			thrd_ship(int iter_max, t_key_hook *hook, int color_scheme)
{
	int			i;
	t_thrd_data *data;
	pthread_t	thrd_tab[4];

	i = -1;
	data = NULL;
	hook->iter_max = iter_max;
	hook->color_scheme = color_scheme;
	while (++i < 4)
	{
		if (!(data = malloc(sizeof(t_thrd_data))))
			return (-1);
		data->thrd_nb = i;
		check_modif(hook, data);
		init_thrd_data(0, 0, data, iter_max);
		data->color_scheme = color_scheme;
		data->rdr = hook->rdr;
		pthread_create(&thrd_tab[i], NULL, calc_ship, data);
	}
	i = -1;
	while (++i < 4)
		pthread_join(thrd_tab[i], NULL);
	mlx_put_image_to_window(hook->mlx->mlx_ptr, hook->mlx->win_ptr,
		hook->rdr->img_ptr, 0, 0);
	return (0);
}
