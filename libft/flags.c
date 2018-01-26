/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:12:43 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:34:05 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*negative_int(char *str, long long data)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = NULL;
	if (data < 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = '-';
		ft_strcpy(result + 1, str);
		free(str);
	}
	return (result ? result : str);
}

char	*alt_flag(char *str, t_format *fmt)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = NULL;
	if (fmt->conv == 'x' || fmt->conv == 'X' || fmt->conv == 'p')
	{
		if (!(result = (char*)ft_memalloc(len + 3)))
			return (NULL);
		result[0] = '0';
		(fmt->conv == 'x' || fmt->conv == 'p') ? result[1] = 'x' : 0;
		fmt->conv == 'X' ? result[1] = 'X' : 0;
		ft_strcpy(result + 2, str);
		free(str);
	}
	if ((fmt->precision == -1 || fmt->precision == 0) && fmt->conv == 'o')
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = '0';
		ft_strcpy(result + 1, str);
		free(str);
	}
	return (result ? result : str);
}

char	*plus_flag(char *str, long long data)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = NULL;
	if (data >= 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = '+';
		ft_strcpy(result + 1, str);
		free(str);
	}
	return (result ? result : str);
}

char	*space_flag(char *str, long long data)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = NULL;
	if (data > 0)
	{
		if (!(result = (char*)ft_memalloc(len + 2)))
			return (NULL);
		result[0] = ' ';
		ft_strcpy(result + 1, str);
		free(str);
	}
	return (result ? result : str);
}
