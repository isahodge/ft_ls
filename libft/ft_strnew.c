/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:08:41 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/16 23:06:23 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;
	char *tmp;

	new = (char*)malloc(sizeof(*new) * size + 1);
	if (new == NULL)
		return (NULL);
	tmp = new;
	while (size > 0)
	{
		*tmp = '\0';
		size--;
		tmp++;
	}
	*tmp = '\0';
	return (new);
}
