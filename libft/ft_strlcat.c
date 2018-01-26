/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 21:24:40 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/21 15:09:22 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		src_len;
	int		dst_len;
	int		max;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if ((int)size <= dst_len)
		return (size + src_len);
	max = size - dst_len - 1;
	while (*dst)
		dst++;
	while (max > 0)
	{
		*dst = *src;
		dst++;
		src++;
		max--;
	}
	*dst = '\0';
	return (src_len + dst_len);
}
