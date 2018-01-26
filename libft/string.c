/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:15:26 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:34:24 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*string_conv(t_format *format, char *str)
{
	char	*result;

	if (str == NULL)
		result = ft_strdup("(null)");
	else
		result = ft_strdup(str);
	if (format->precision >= 0)
		result = str_precision(result, format->precision);
	if (format->mfw)
		result = mfw_char(result, format);
	format->strlength = ft_strlen(result);
	return (result);
}

void	char_conv(t_format *format, unsigned char c)
{
	int i;

	i = 1;
	if (format->mfw)
	{
		format->minus ? ft_putchar(c) : 0;
		while (format->mfw > 1)
		{
			ft_putchar(' ');
			format->mfw--;
			i++;
		}
		format->minus ? 0 : ft_putchar(c);
	}
	else
		ft_putchar(c);
	format->strlength = i;
}

char	*str_precision(char *str, int precision)
{
	char	*result;
	int		len;

	result = NULL;
	len = ft_strlen(str);
	if (len > precision)
	{
		result = ft_strsub(str, 0, precision);
		free(str);
	}
	return (result ? result : str);
}

void	str_fill_before(char *str, char **result, int fill, t_format *format)
{
	int		i;
	char	character;

	character = ' ';
	if (format->zero && format->precision == -1)
		character = '0';
	i = 0;
	while (fill)
	{
		(*result)[i] = character;
		i++;
		fill--;
	}
	ft_strcpy((*result) + i, str);
}

char	*mfw_char(char *str, t_format *format)
{
	char	*result;
	int		len;
	int		fill;

	result = NULL;
	len = ft_strlen(str);
	fill = format->mfw - len;
	if (fill > 0)
	{
		if (!(result = (char*)malloc(len + fill + 1)))
			return (NULL);
		if (format->minus)
			fill_after(str, &result, fill);
		else
			str_fill_before(str, &result, fill, format);
		free(str);
	}
	return (result ? result : str);
}
