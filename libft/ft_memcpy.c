/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:38:38 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 21:18:43 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp;

	tmp = dst;
	while (n > 0)
	{
		*(char*)tmp = *(char*)src;
		tmp++;
		src++;
		n--;
	}
	return (dst);
}
