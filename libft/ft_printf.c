/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:06:54 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:32:30 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	save_signs(t_format *format, char c)
{
	if (c == ' ')
		format->space = 1;
	else if (c == '+')
		format->plus = 1;
	else if (c == '-')
		format->minus = 1;
	else if (c == '#')
		format->alternate = 1;
}

void	save_flag(t_format *format, char *str)
{
	int		num;

	while (*str != '\0' && is_flag(*str) >= 1)
	{
		if (*str == '.')
			format->precision = 0;
		if (is_flag(*str) == 2)
		{
			num = 0;
			if (*str == '0' && format->precision == -1)
				format->zero = 1;
			while (is_flag(*str) == 2)
			{
				num = num * 10 + *str - '0';
				str++;
			}
			str--;
			if (format->precision == 0)
				format->precision = num;
			else
				format->mfw = num;
		}
		save_signs(format, *str);
		str++;
	}
}

void	write_arg(va_list ap, t_format *format, char conv)
{
	char *string;

	string = NULL;
	format->conv = conv;
	if (conv == 'i' || conv == 'd' || conv == 'D')
	{
		string = dispatcher(format, va_arg(ap, long long));
		ft_putstr(string);
		free(string);
	}
	if (conv == 'u' || conv == 'o' || conv == 'x' || conv == 'X' ||
			conv == 'p' || conv == 'U' || conv == 'O')
	{
		string = u_dispatcher(format, va_arg(ap, unsigned long));
		ft_putstr(string);
		free(string);
	}
	if (conv == 'c' || conv == 'C')
		char_conv(format, ((unsigned char)va_arg(ap, int)));
	if (conv == 's' || conv == 'S')
	{
		string = string_conv(format, va_arg(ap, char *));
		ft_putstr(string);
		free(string);
	}
}

int		process_arg(va_list ap, char *str, int *length, t_format *format)
{
	int i;

	i = 1;
	format = create_format();
	save_flag(format, (char*)str + 1);
	while (is_flag(str[i]))
		i++;
	if (str[i] == '%')
	{
		char_conv(format, '%');
		(*length) += format->strlength;
		free(format);
		return (i + 1);
	}
	str += i;
	i += is_length((char*)str, format);
	str += is_length((char*)str, format);
	if (is_conv(*str) == 1)
	{
		write_arg(ap, format, *str);
		(*length) += format->strlength;
		i++;
	}
	free(format);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_format	*format;
	int			length;

	format = NULL;
	length = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			str += process_arg(ap, (char*)str, &length, format);
		else if (*str)
		{
			ft_putchar(*str);
			length++;
			str++;
		}
	}
	va_end(ap);
	return (length);
}
