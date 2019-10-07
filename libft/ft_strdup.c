/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 21:41:55 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 08:08:00 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		cpt;

	cpt = -1;
	if ((dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	while (src[++cpt] != '\0')
		dest[cpt] = src[cpt];
	dest[cpt] = '\0';
	return (dest);
}
