/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 05:24:28 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 18:23:52 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		max_size;

	if (s1 == NULL || s2 == NULL)
		return (0);
	max_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(joined = (char *)malloc(max_size)))
		return (0);
	while (*s1)
		*(joined++) = *s1++;
	while (*s2)
		*(joined++) = *s2++;
	*joined = '\0';
	return (joined - (max_size - 1));
}
