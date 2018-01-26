/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 00:04:22 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/06 19:34:16 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	get_length_pls(int *i, unsigned long *tmp, unsigned int base)
{
	while ((*tmp) >= base)
	{
		(*tmp) = (*tmp) / base;
		(*i) = (*i) + 1;
	}
}

char	*ft_itoa_base(unsigned int base, unsigned long val)
{
	int				i;
	char			*str;
	unsigned long	tmp;
	int				character;

	character = 'a';
	i = 1;
	tmp = val;
	get_length_pls(&i, &tmp, base);
	if (!(str = (char*)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		tmp = val % base;
		str[i] = tmp >= 10 ? tmp - 10 + character : tmp + '0';
		val = val / base;
	}
	return (str);
}
