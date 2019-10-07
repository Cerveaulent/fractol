/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_words.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 07:50:12 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 00:26:20 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *str, char c)
{
	int cpt;
	int i;

	cpt = 1;
	i = -1;
	while (str[++i])
	{
		while (str[i] != c && str[i])
			i++;
		if (str[i] == c && str[i + 1] != c)
			cpt++;
	}
	return (cpt);
}
