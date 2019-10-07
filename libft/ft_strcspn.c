/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 13:59:09 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 14:18:33 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(s + j) && *(s + j) != *(charset + i))
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
