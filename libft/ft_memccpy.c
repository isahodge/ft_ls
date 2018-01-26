/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:47:14 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 14:13:49 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dst = (unsigned char)c;
			dst++;
			return (dst);
		}
		*(unsigned char*)dst = *(unsigned char*)src;
		src++;
		dst++;
		n--;
	}
	return (NULL);
}
