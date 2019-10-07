/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 11:50:14 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 00:39:55 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		len_str;

	i = 0;
	if (str == NULL)
		return (NULL);
	len_str = ft_strlen(str);
	while (i <= len_str)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
