/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 21:24:42 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 21:25:14 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*fresh;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(*fresh) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (fresh == NULL)
		return (NULL);
	while (*s1)
		fresh[i++] = *s1++;
	while (*s2)
		fresh[i++] = *s2++;
	fresh[i] = '\0';
	return (fresh);
}
