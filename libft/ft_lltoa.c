/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:00:37 by ihodge            #+#    #+#             */
/*   Updated: 2017/12/27 14:32:49 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static void	ft_reverse(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

static int	ft_intlen(long long n, int int_len)
{
	if (n == -9223372036854775807 - 1)
		return (20);
	if (n < 0)
	{
		n *= -1;
		int_len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		int_len++;
	}
	return (int_len);
}

char		*ft_lltoa(long long n)
{
	char	*fresh;
	int		int_len;
	int		i;

	i = 0;
	int_len = ft_intlen(n, 1);
	fresh = ft_strnew(int_len);
	if (fresh == NULL)
		return (NULL);
	if (n == -9223372036854775807 - 1)
		return (ft_strcpy(fresh, "9223372036854775808"));
	fresh[int_len - 1] = n < 0 ? '-' : '0';
	if (n < 0)
		n = -n;
	while (i < int_len && n > 0)
	{
		fresh[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	ft_reverse(fresh);
	return (fresh);
}
