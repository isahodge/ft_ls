/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 00:09:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 20:59:56 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*locate;

	locate = NULL;
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			locate = (unsigned char*)s;
			return (locate);
		}
		s++;
		n--;
	}
	return (NULL);
}
