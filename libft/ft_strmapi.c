/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 03:20:05 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 20:41:46 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fresh;

	if (!s)
		return (NULL);
	i = 0;
	fresh = (char*)malloc(sizeof(*fresh) * ft_strlen(s) + 1);
	if (fresh == NULL)
		return (NULL);
	while (*s)
	{
		fresh[i] = f(i, *(char*)s);
		i++;
		s++;
	}
	fresh[i] = '\0';
	return (fresh);
}
