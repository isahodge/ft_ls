/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 01:12:16 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/17 21:28:22 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*locate;
	char	*tmp;
	int		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		i = 0;
		if (*little == *big)
		{
			locate = (char*)big;
			tmp = (char*)big;
			while (little[i++] == *(tmp++))
			{
				if (little[i] == '\0')
					return (locate);
			}
		}
		big++;
	}
	return (NULL);
}
