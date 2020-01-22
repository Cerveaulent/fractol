/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtok.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/16 04:23:08 by raging       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 20:48:03 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtok_r(char *s, const char *delim, char **s_ptr)
{
	char		*pos;

	s == NULL ? s = *s_ptr : 0;
	if (!(*s))
	{
		*s_ptr = s;
		return (NULL);
	}
	s += ft_strspn(s, delim);
	if (!(*s))
	{
		*s_ptr = s;
		return (NULL);
	}
	pos = s + ft_strcspn(s, delim);
	if (*pos == '\0')
	{
		*s_ptr = pos;
		return (s);
	}
	*pos = '\0';
	*s_ptr = pos + 1;
	return (s);
}

char		*ft_strtok(char *s, const char *delim)
{
	static char	*olds;
	
	return (ft_strtok_r(s, delim, &olds));
}
