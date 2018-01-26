/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:00:34 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 21:27:47 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*locate;

	locate = NULL;
	if (*s == '\0' && c == '\0')
	{
		locate = (char *)s;
		return (locate);
	}
	while (*s)
	{
		if (c == *s)
		{
			locate = (char *)s;
		}
		s++;
		if (*s == '\0' && c == '\0')
		{
			locate = (char *)s;
			return (locate);
		}
	}
	if (locate != NULL)
		return (locate);
	return (NULL);
}
