/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:25:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 17:36:40 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void print_invalid_args(void)
{
	ft_putendl("Invalid arguments");
	ft_putendl("usage :");
	ft_putendl("./fractol Mandelbrot");
	ft_putendl("Fractals available : Mandelbrot, Julia, placeholder");
}

static int check_args(int ac, char *av)
{
	if(ac != 2)
	{
		print_invalid_args();
		return (-1);
	}
	if(ft_strcmp(av, "Mandelbrot") && ft_strcmp(av, "Julia") &&
		ft_strcmp(av, "Placeholder"))
	{
		print_invalid_args();
		return (-1);
	}
	else
		return (0);
}

static void	launch(char *av, t_key_hook *hook)
{
	if (!ft_strcmp(av, "Mandelbrot"))
	{
		hook->fract_t = MANDEL;
		thrd_mandel(hook->iter_max, hook, hook->color_scheme);
	}
	else if (!ft_strcmp(av, "Julia"))
	{
		hook->fract_t = JULIA;
		thrd_julia(hook->iter_max, hook, hook->color_scheme);
	}
	if (!ft_strcmp(av, "Placeholder"))
		return ;
}

int		main(int argc, char **argv)
{
	t_key_hook	*hook;

	if (check_args(argc, argv[1]))
		return (-1);
	hook = init_hook(2);
	launch(argv[1], hook);
	mlx_hook(hook->mlx->win_ptr, 2, (1L << 17), key_pressed, hook);
	mlx_mouse_hook(hook->mlx->win_ptr, mouse_pressed, hook);
	mlx_hook(hook->mlx->win_ptr, 6, (1L << 6), NULL, hook);
	mlx_loop(hook->mlx->mlx_ptr);
	return (0);
}
