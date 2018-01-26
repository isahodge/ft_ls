/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:30:57 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/18 18:05:17 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	char	*first;
	char	*last;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhitespace(*s) == 1)
	{
		s++;
		start++;
	}
	first = (char *)s;
	last = (char *)s;
	while (*s)
	{
		if (ft_iswhitespace(*s) != 1)
			last = (char *)s;
		s++;
	}
	fresh = ft_strsub(first, 0, last - first + 1);
	if (fresh == NULL)
		return (NULL);
	return (fresh);
}
