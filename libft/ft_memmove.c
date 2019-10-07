/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 02:16:44 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 08:06:56 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = len;
	if (src < dst && (src + len - 1) >= dst)
	{
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
		return (dst);
	}
	else
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dst - i);
}
