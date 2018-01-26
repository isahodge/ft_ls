/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:37:54 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/07 14:47:53 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sticky_guid_suid(char *str, char *mode, int mode_len)
{
	str[3] = mode[mode_len - 4] == '4' && str[3] == 'x' ? 's' : str[3];
	str[3] = mode[mode_len - 4] == '4' && str[3] == '-' ? 'S' : str[3];
	str[6] = mode[mode_len - 4] == '2' && str[6] == 'x' ? 's' : str[6];
	str[6] = mode[mode_len - 4] == '2' && str[6] == '-' ? 'S' : str[6];
	str[9] = mode[mode_len - 4] == '1' && str[9] == 'x' ? 't' : str[9];
	str[9] = mode[mode_len - 4] == '1' && str[9] == '-' ? 'T' : str[9];
}

void	more_trans_mode(char *str, mode_t t_mode, char *mode, int mode_len)
{
	str[0] = S_ISBLK(t_mode) ? 'b' : '-';
	str[0] = S_ISCHR(t_mode) ? 'c' : str[0];
	str[0] = S_ISDIR(t_mode) ? 'd' : str[0];
	str[0] = S_ISLNK(t_mode) ? 'l' : str[0];
	str[1] = mode[mode_len - 3] == '7' || mode[mode_len - 3] == '6' ||
			mode[mode_len - 3] == '5' || mode[mode_len - 3] == '4' ? 'r' : '-';
	str[2] = mode[mode_len - 3] == '7' || mode[mode_len - 3] == '6' ||
			mode[mode_len - 3] == '3' || mode[mode_len - 3] == '2' ? 'w' : '-';
	str[3] = mode[mode_len - 3] == '7' || mode[mode_len - 3] == '5' ||
			mode[mode_len - 3] == '3' ? 'x' : '-';
	str[4] = mode[mode_len - 2] == '7' || mode[mode_len - 2] == '6' ||
			mode[mode_len - 2] == '5' || mode[mode_len - 2] == '4' ? 'r' : '-';
	str[5] = mode[mode_len - 2] == '7' || mode[mode_len - 2] == '6' ||
			mode[mode_len - 2] == '3' || mode[mode_len - 2] == '2' ? 'w' : '-';
	str[6] = mode[mode_len - 2] == '7' || mode[mode_len - 2] == '5' ||
			mode[mode_len - 2] == '3' ? 'x' : '-';
	str[7] = mode[mode_len - 1] == '7' || mode[mode_len - 1] == '6' ||
			mode[mode_len - 1] == '5' || mode[mode_len - 1] == '4' ? 'r' : '-';
	str[8] = mode[mode_len - 1] == '7' || mode[mode_len - 1] == '6' ||
			mode[mode_len - 1] == '3' || mode[mode_len - 1] == '2' ? 'w' : '-';
	str[9] = mode[mode_len - 1] == '7' || mode[mode_len - 1] == '5' ||
			mode[mode_len - 1] == '3' ? 'x' : '-';
	sticky_guid_suid(str, mode, mode_len);
}

void	x_attr(char *str, t_stat *files)
{
	int buflen;

	buflen = listxattr(files->path, 0, 0, 0);
	if (buflen <= 0)
	{
		str[10] = ' ';
	}
	else
		str[10] = '@';
}

char	*translate_mode(char *mode, mode_t t_mode, t_stat *files)
{
	char	*str;
	int		int_mode;
	int		mode_len;

	mode_len = ft_strlen(mode);
	int_mode = ft_atoi(mode);
	str = (char*)ft_memalloc(12);
	more_trans_mode(str, t_mode, mode, mode_len);
	x_attr(str, files);
	str[11] = '\0';
	return (str);
}
