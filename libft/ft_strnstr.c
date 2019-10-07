/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 22:49:59 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:37:58 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (!needle[0] || haystack == needle)
		return ((char *)haystack);
	while (*haystack && !(i = 0) && len != 0 && i <= --len)
	{
		while (needle[i] && needle[i] == haystack[i] && i <= len)
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
