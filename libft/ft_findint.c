/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_findint.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 17:54:16 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 18:07:52 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long int			ft_findint(int *tab_int, int to_find, size_t size)
{
	long int		i;

	i = 0;
	while ((size_t)i < size)
	{
		if (tab_int[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}
