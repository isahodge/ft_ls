/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:22:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/18 18:40:11 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*fresh;
	t_list	*tmp;

	if (!(head = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp = NULL;
	while (lst != NULL)
	{
		if (!(fresh = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		fresh = f(lst);
		if (tmp != NULL)
			tmp->next = fresh;
		else
			head = fresh;
		tmp = fresh;
		lst = lst->next;
	}
	return (head);
}
