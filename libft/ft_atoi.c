/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:03:03 by ihodge            #+#    #+#             */
/*   Updated: 2017/06/16 18:04:54 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exceptions(char c, const char *str)
{
	int true;

	true = 0;
	if (c == ' ' || c == '\n' || c == '\t')
		true = 1;
	else if (c == '\r' || c == '\v' || c == '\f')
		true = 1;
	else if (c == '+' && *(str + 1) >= '0' && *(str + 1) <= '9')
		true = 1;
	else if (c == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
		true = -1;
	else if (c < '0' || c > '9')
		true = 2;
	return (true);
}

int			ft_atoi(const char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (*str)
	{
		if (exceptions(*str, str) != 0)
		{
			if (exceptions(*str, str) == -1)
				sign = -1;
			if (exceptions(*str, str) == 2)
				break ;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			res = res * 10 + *str - '0';
			str++;
			if (*str < '0' || *str > '9')
				return (sign * res);
		}
	}
	return (0);
}
