/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:49:23 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 16:09:25 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		cpt;

	cpt = 0;
	while (cpt < len && src[cpt] != '\0')
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	while (cpt < len)
	{
		dst[cpt] = '\0';
		cpt++;
	}
	return (dst);
}
