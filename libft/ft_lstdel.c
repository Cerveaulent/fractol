/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 09:51:58 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 12:09:51 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*alst)->next)
	{
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
