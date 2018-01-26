/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:13:26 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/18 15:40:12 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*locate;
	char	*tmp;
	size_t	i;
	size_t	len_tmp;

	if (*little == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		i = 0;
		if (*little == *big)
		{
			locate = (char *)big;
			tmp = (char *)big;
			len_tmp = len;
			while ((little[i++] == *(tmp++)) && len_tmp-- > 0)
			{
				if (little[i] == '\0')
					return (locate);
			}
		}
		big++;
		len--;
	}
	return (NULL);
}
