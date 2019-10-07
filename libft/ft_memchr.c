/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 18:02:47 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 08:06:38 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ret;

	ret = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*(unsigned char*)ret == (unsigned char)c)
			return (ret);
		ret++;
	}
	return (NULL);
}
