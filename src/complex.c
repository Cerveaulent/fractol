/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   complex.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 14:56:33 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 16:51:01 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

double		complex_mod(t_complex com)
{
	return (sqrt(com.real * com.real + com.imagi * com.imagi));
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex res;

	res.real = a.real + b.real;
	res.imagi = a.imagi + b.imagi;
	return (res);
}

t_complex	complex_mul(t_complex a, t_complex b)
{
	t_complex res;

	res.real = a.real * b.real - a.imagi * b.imagi;
	res.imagi = a.real * b.imagi + a.imagi * b.real;
	return (res);
}

t_complex	complex_scal_mul(t_complex a, int scal)
{
	t_complex res;

	res.real = a.real * scal;
	res.imagi = a.imagi * scal;
	return (res);
}

t_complex	complex_subst(t_complex a, t_complex b)
{
	t_complex res;

	res.real = a.real - b.real;
	res.imagi = a.imagi - b.imagi;
}