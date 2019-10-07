/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 03:37:37 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 18:03:24 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char	const *s, char (*f)(char))
{
	char	*res;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(res = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (*s)
		(res[i++]) = f(*s++);
	res[i] = '\0';
	return (res);
}
