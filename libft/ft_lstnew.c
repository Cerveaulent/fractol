/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 08:44:52 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 16:27:02 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(new_lst->content = (void *)malloc(content_size)))
			return (NULL);
		new_lst->content = (void *)ft_memcpy(new_lst->content,
			content, content_size);
		new_lst->content_size = content_size;
	}
	else
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	new_lst->next = NULL;
	return (new_lst);
}
