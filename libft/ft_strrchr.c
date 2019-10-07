/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:52:24 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 00:51:02 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		else
			i--;
	}
	return (NULL);
}
