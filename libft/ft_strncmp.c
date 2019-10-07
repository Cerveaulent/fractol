/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 17:33:11 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:37:19 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t cpt;

	cpt = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && cpt < n - 1)
	{
		if (*s1 > *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 < *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		cpt++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
