/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:42:37 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:33:08 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	set_var(t_format *format, union u_data_union du, unsigned int *base,
		unsigned long *val)
{
	if (format->conv == 'x' || format->conv == 'X' || format->conv == 'p')
		*base = 16;
	else if (format->conv == 'o')
		*base = 8;
	else
		*base = 10;
	if (format->length == 'H')
		*val = du.uchar;
	else if (format->length == 'h')
		*val = du.ushort;
	else if (format->length == 'l')
		*val = du.ulong;
	else if (format->length == 'X')
		*val = du.ulong;
	else if (format->length == 'j')
		*val = du.uintmaxt;
	else if (format->length == 'z')
		*val = du.usizet;
	else
		*val = du.uint;
}

void	get_length(int *i, unsigned long *tmp, unsigned int base)
{
	while ((*tmp) >= base)
	{
		(*tmp) = (*tmp) / base;
		(*i) = (*i) + 1;
	}
}

char	*ft_ultoa_base(union u_data_union du, t_format *format,
		unsigned int base)
{
	int				i;
	char			*str;
	unsigned long	tmp;
	int				character;
	unsigned long	val;

	set_var(format, du, &base, &val);
	character = 'a';
	if (format->conv == 'X')
		character = 'A';
	i = 1;
	tmp = val;
	get_length(&i, &tmp, base);
	if (!(str = (char*)ft_memalloc(i + 1)))
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
