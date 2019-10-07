/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 16:41:14 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 17:30:02 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	if (!needle[0] || haystack == needle)
		return ((char *)haystack);
	while (*haystack && !(i = 0))
	{
		while (needle[i] && needle[i] == haystack[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
