/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 05:52:16 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 18:18:24 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		cpt;
	char	*trimmed;
	int		i;

	if (s == NULL)
		return (NULL);
	cpt = 0;
	while (s[cpt] == '\n' || s[cpt] == '\t' || s[cpt] == '\v' || s[cpt] == '\r'
		|| s[cpt] == '\f' || s[cpt] == ' ')
		cpt++;
	i = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == '\v' || s[i] == '\r'
		|| s[i] == '\f' || s[i] == ' ')
		i--;
	if (i < 1)
	{
		if (!(trimmed = (char *)malloc(1)))
			return (NULL);
		trimmed[0] = '\0';
	}
	else
		trimmed = ft_strsub(s, cpt, i + 1 - cpt);
	return (trimmed);
}
