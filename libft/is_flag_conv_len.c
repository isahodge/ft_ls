/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_conv_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:23:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:33:37 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_flag(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == ' ' || c == '.' ||
			c == 'm')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

int		is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'o' || c == 'O' ||
			c == 'u' || c == 'U' || c == 'D' || c == 'p' || c == 'c' ||
			c == 's' || c == 'C' || c == 'S')
		return (1);
	return (0);
}

int		is_length(char *str, t_format *format)
{
	if ((*str == 'h' && *(str + 1) == 'h') && is_conv(*(str + 2)))
	{
		format->length = 'H';
		return (2);
	}
	else if ((*str == 'l' && *(str + 1) == 'l') && is_conv(*(str + 2)))
	{
		format->length = 'X';
		return (2);
	}
	else if ((*str == 'l' || *str == 'h' || *str == 'j' || *str == 'z')
			&& is_conv(*(str + 1)))
	{
		format->length = *str;
		return (1);
	}
	return (0);
}
