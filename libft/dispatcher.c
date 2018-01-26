/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:16:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:33:51 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dispatcher(t_format *format, long long data)
{
	char	*result;

	result = NULL;
	if (format->conv == 'D')
	{
		format->conv = 'd';
		format->length = 'l';
	}
	result = fptr_with_length(format->conv, format->length, &data);
	if (format->precision >= 0)
		result = int_precision(result, format->precision, data);
	if (data < 0)
		result = negative_int(result, data);
	if (format->plus)
		result = plus_flag(result, data);
	if (format->space && !format->plus)
		result = space_flag(result, data);
	if (format->zero || format->mfw)
		result = min_field_wid(result, format);
	format->strlength = ft_strlen(result);
	return (result);
}

void	change_conv(t_format *format)
{
	if (format->conv == 'p')
	{
		format->alternate = 1;
		format->length = 'l';
	}
	else if (format->conv == 'U')
	{
		format->conv = 'u';
		format->length = 'l';
	}
	else if (format->conv == 'O')
	{
		format->conv = 'o';
		format->length = 'l';
	}
}

char	*u_dispatcher(t_format *format, unsigned long data)
{
	char	*result;

	result = NULL;
	if (format->conv == 'p' || format->conv == 'O' || format->conv == 'U')
		change_conv(format);
	result = ufptr_with_length(format, &data);
	if (format->precision >= 0)
		result = int_precision(result, format->precision, data);
	if (format->alternate && (data > 0 || format->conv == 'p'))
		result = alt_flag(result, format);
	if (format->zero || format->mfw)
		result = min_field_wid(result, format);
	format->strlength = ft_strlen(result);
	return (result);
}

char	*fptr_with_length(char c, char l, long long *data)
{
	char	*(*fptr[127]) (long long data);

	ft_bzero(fptr, 127);
	fptr['i'] = ft_lltoa;
	fptr['d'] = ft_lltoa;
	if (l == 'H')
		*data = (char)*data;
	else if (l == 'h')
		*data = (short)*data;
	else if (l == 'l')
		*data = (long)*data;
	else if (l == 'X')
		return ((*fptr[(int)c])(*data > 0 ? *data : *data * -1));
	else if (l == 'j')
		*data = (intmax_t) * data;
	else if (l == 'z')
		*data = (size_t)*data;
	else
		*data = (int)*data;
	return ((*fptr[(int)c])(*data > 0 ? *data : *data * -1));
}

char	*ufptr_with_length(t_format *format, unsigned long *data)
{
	union u_data_union	du;
	t_ufptr				ufunct[127];

	ft_bzero(ufunct, 127);
	du.ulong = *data;
	ufunct['u'] = ft_ultoa_base;
	ufunct['o'] = ft_ultoa_base;
	ufunct['x'] = ft_ultoa_base;
	ufunct['X'] = ft_ultoa_base;
	ufunct['p'] = ft_ultoa_base;
	return ((ufunct[(int)format->conv])(du, format, 0));
}
