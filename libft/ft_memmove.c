/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:59:21 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 21:19:29 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_tmp;
	char	*dst_tmp;

	dst_tmp = (char*)dst + len - 1;
	src_tmp = (char*)src + len - 1;
	if (src < dst)
	{
		while (len > 0)
		{
			*dst_tmp = *src_tmp;
			dst_tmp--;
			src_tmp--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
