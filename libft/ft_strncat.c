/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 22:06:41 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 16:22:33 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *orig, const char *append, size_t len)
{
	char	*tmp;
	size_t	cpt;

	cpt = 0;
	tmp = orig;
	while (*orig != '\0')
		orig++;
	while (cpt < len && append[cpt])
	{
		*orig = append[cpt++];
		orig++;
	}
	*orig = '\0';
	return (tmp);
}
