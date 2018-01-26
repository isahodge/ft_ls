/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:16:03 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/18 15:39:57 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*fresh;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(*fresh) * len + 1)))
		return (NULL);
	while (i < len)
	{
		fresh[i] = ((char *)s)[start];
		start++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
