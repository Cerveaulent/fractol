/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strspn.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 14:39:45 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 14:18:18 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(s + j) && *(s + j) == *(charset + i))
	{
		if (!*(charset + i))
		{
			i = -1;
			j++;
		}
		i++;
	}
	return (j);
}
