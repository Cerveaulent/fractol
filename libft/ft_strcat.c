/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 20:31:39 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 16:15:57 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *orig, const char *append)
{
	char	*tmp;

	tmp = orig;
	while (*orig)
		orig++;
	while (*append)
		*orig++ = *append++;
	*orig = '\0';
	return (tmp);
}
