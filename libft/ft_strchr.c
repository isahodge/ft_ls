/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:57:11 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 21:20:46 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *locate;

	if (*s == '\0' && c == 0)
	{
		locate = (char *)s;
		return (locate);
	}
	while (*s)
	{
		if (c == *s)
		{
			locate = (char *)s;
			return (locate);
		}
		s++;
		if (*s == '\0' && c == 0)
		{
			locate = (char *)s;
			return (locate);
		}
	}
	return (NULL);
}
