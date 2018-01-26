/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:37:25 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/19 20:22:57 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_del(char const *s, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (s[i])
	{
		while ((char)s[i] == c)
			i++;
		while ((char)s[i] != c && (char)s[i] != '\0')
		{
			len++;
			i++;
		}
		if ((char)s[i] == c || (char)s[i] == '\0')
			return (len);
	}
	return (len);
}

static int	count_del_str(char const *s, char c)
{
	int i;
	int strings;

	strings = 0;
	i = 0;
	while (s[i])
	{
		while ((char)s[i] == c && (char)s[i] != '\0')
			i++;
		if ((char)s[i] != c && (char)s[i] != '\0')
			strings++;
		while (s[i] != c && (char)s[i] != '\0')
			i++;
	}
	return (strings);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		strings;
	int		strlen;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strings = count_del_str(s, c);
	if (!(arr = (char**)malloc(sizeof(*arr) * (strings + 1))))
		return (NULL);
	while (i < strings)
	{
		if (*s != c)
		{
			strlen = strlen_del(s, c);
			if (!(arr[i++] = ft_strsub(s, 0, strlen)))
				return (NULL);
			s += strlen;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
