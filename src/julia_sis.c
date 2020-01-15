/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia_sis.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 21:33:44 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 19:51:00 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int check_modif(t_key_hook *k_hook, t_thrd_data *data)
{
	if (k_hook->x_min != JU_X_MIN || k_hook->y_min != JU_Y_MIN 
		|| k_hook->zoom != data->zoom || k_hook->ju_move == 1)
	{
		data->x_min = k_hook->x_min;
		data->y_min = k_hook->y_min;
		data->zoom = k_hook->zoom;
		data->ju_move = k_hook->ju_move;
		data->mouse_x = k_hook->mouse_x;
		data->mouse_y = k_hook->mouse_y;
		data->c.real = data->mouse_x / data->zoom + data->x_min;
		data->c.imagi = data->mouse_y / data->zoom + data->y_min;
	}	
	else
	{
		init_fract(k_hook->fract_t, k_hook);
		data->c.real = -0.70176;
		data->c.imagi = -0.3842;
	}
	return (1);
}

static void	init_thrd_data(double x, double y, t_thrd_data *data, int iter_max)
{
	data->zn.real = x / data->zoom + data->x_min;
	data->zn.imagi = y / data->zoom + data->y_min;
	// if (data->ju_move == 1 || )
	// {
	// 	data->c.real = data->mouse_x / data->zoom + data->x_min;
	// 	data->c.imagi = data->mouse_y / data->zoom + data->y_min;
	// }
	// else
	// {
	// 	data->c.real = -0.70176;
	// 	data->c.imagi = -0.3842;
	// }
	data->iter_max = iter_max;
	data->iter_act = 0;
}

static int		rec_calc_julia(t_thrd_data *data)
{
	data->zn = complex_add(complex_mul(data->zn,data->zn), data->c);
	if (data->iter_max > data->iter_act && ((data->zn.real * data->zn.real +
		data->zn.imagi * data->zn.imagi) < 4))
	{
		data->iter_act += 1;
		return (rec_calc_julia(data));
	}
	else
		return (0);
}

static void	*calc_julia(void *data)
{
	t_pts		pt;
	t_thrd_data *tmp;
	float		p;

	p = (pt.x - 0.25) * (pt.x - 0.25) + (pt.y * pt.y);
	tmp = (t_thrd_data *)data;
	pt.y = tmp->rdr->r_hei * (tmp->thrd_nb) * 0.25;
	while(pt.y < (tmp->rdr->r_hei * (tmp->thrd_nb + 1)) * 0.25)
	{
		pt.x = 0;
		while((int)pt.x < tmp->rdr->r_wid)
		{
			init_thrd_data(pt.x, pt.y, tmp, tmp->iter_max);
			rec_calc_julia(tmp);
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

int		thrd_julia(int iter_max, t_key_hook *k_hook, int color_scheme)
{
	int i;
	t_thrd_data *data;
	pthread_t	thrd_tab[4];

	i = -1;
	data = NULL;
	k_hook->iter_max = iter_max;
	k_hook->color_scheme = color_scheme;
	while (++i < 4)
	{
		if(!(data = malloc(sizeof(t_thrd_data))))
			return (-1);
		data->thrd_nb = i;
		check_modif(k_hook, data);
		init_thrd_data(0, 0, data, iter_max);
		data->color_scheme = color_scheme;
		data->rdr = k_hook->rdr;
		pthread_create(&thrd_tab[i], NULL, calc_julia, data);
	}
	i = -1;
	while (++i < 4)
		pthread_join(thrd_tab[i], NULL);
	mlx_put_image_to_window(k_hook->mlx->mlx_ptr, k_hook->mlx->win_ptr,
		k_hook->rdr->img_ptr, 0, 0);
	return (0);
}