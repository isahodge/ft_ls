/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 21:24:42 by ihodge            #+#    #+#             */
/*   Updated: 2017/11/02 21:13:43 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoinf(const char *s1, const char *s2)
{
	char	*fresh;
	int		i;
	char	*s1_tmp;
	char	*s2_tmp;

	i = 0;
	s1_tmp = (char*)s1;
	s2_tmp = (char*)s2;
	if (!s1_tmp || !s2_tmp)
		return (NULL);
	fresh = (char *)malloc(sizeof(*fresh) * ft_strlen(s1_tmp) +
			ft_strlen(s2_tmp) + 1);
	if (fresh == NULL)
		return (NULL);
	while (*s1_tmp)
		fresh[i++] = *s1_tmp++;
	while (*s2_tmp)
		fresh[i++] = *s2_tmp++;
	fresh[i] = '\0';
	free((char*)s1);
	free((char*)s2);
	return (fresh);
}
