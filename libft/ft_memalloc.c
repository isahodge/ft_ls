/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 02:33:29 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/18 16:17:29 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;
	char	*tmp;

	if (!(fresh = (void*)malloc(sizeof(*fresh) * size)))
		return (NULL);
	tmp = fresh;
	while (size > 0)
	{
		*tmp = 0;
		tmp++;
		size--;
	}
	return (fresh);
}
