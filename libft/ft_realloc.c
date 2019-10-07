/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 17:52:36 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 14:53:13 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size, size_t size_ptr)
{
	void	*new_pt;

	if (size != 0 && !(ptr == NULL))
	{
		new_pt = ft_memalloc(size);
		if (new_pt)
		{
			ft_bzero(new_pt, size);
			ft_memcpy(new_pt, ptr, size_ptr);
		}
		free(ptr);
		return (new_pt);
	}
	else
		return (NULL);
}
