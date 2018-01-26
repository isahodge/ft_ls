/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:22:57 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 21:19:55 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;

	tmp = (char *)b;
	while (len > 0)
	{
		*(unsigned char*)tmp = (unsigned char)c;
		len--;
		tmp++;
	}
	return (b);
}
