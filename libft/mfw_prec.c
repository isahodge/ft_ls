/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfw_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:13:24 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:34:52 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*int_precision(char *str, int precision, int data)
{
	int		len;
	int		fill;
	char	*result;

	len = ft_strlen(str);
	result = NULL;
	fill = precision - len;
	if (data == 0 && precision == 0)
	{
		result = ft_strdup("");
		free(str);
	}
	else if (fill > 0)
	{
		if (!(result = (char*)ft_memalloc(len + fill + 1)))
			return (NULL);
		fill_before(str, &result, fill, '0');
		free(str);
	}
	return (result ? result : str);
}

void	fill_after(char *str, char **result, int fill)
{
	int i;

	i = 0;
	while (*str)
	{
		(*result)[i] = *str;
		str++;
		i++;
	}
	while (fill)
	{
		(*result)[i] = ' ';
		i++;
		fill--;
	}
	(*result)[i] = '\0';
}

void	fill_before(char *str, char **result, int fill, char character)
{
	int i;

	i = 0;
	if ((*str == '+' || *str == '-' || *str == ' ') && character == '0')
	{
		(*result)[i++] = *str;
		str++;
	}
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')
			&& character == '0')
	{
		(*result)[i++] = *str;
		(*result)[i++] = *(str + 1);
		str += 2;
	}
	while (fill)
	{
		(*result)[i] = character;
		i++;
		fill--;
	}
	ft_strcpy((*result) + i, str);
}

char	*min_field_wid(char *str, t_format *format)
{
	int		len;
	int		fill;
	char	*result;
	char	character;

	result = NULL;
	len = ft_strlen(str);
	fill = format->mfw - len;
	character = ' ';
	if (fill > 0)
	{
		if (!(result = (char*)malloc(len + fill + 1)))
			return (NULL);
		if (format->minus)
			fill_after(str, &result, fill);
		else
		{
			if (format->zero && format->precision == -1)
				character = '0';
			fill_before(str, &result, fill, character);
		}
		free(str);
	}
	return (result ? result : str);
}
