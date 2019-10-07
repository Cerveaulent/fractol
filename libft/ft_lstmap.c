/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 11:08:47 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 12:51:13 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	new = f(lst);
	return (tmp);
}
