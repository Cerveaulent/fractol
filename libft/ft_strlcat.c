/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 22:07:02 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 16:30:05 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	if (size <= len_dst)
		return (len_src + size);
	while (i < size - 1 && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (len_src + len_dst);
}
