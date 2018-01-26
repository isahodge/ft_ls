/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 18:51:28 by ihodge            #+#    #+#             */
/*   Updated: 2017/08/09 20:20:51 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*create_lst(int fd)
{
	t_lst	*new;

	if (!(new = (t_lst*)ft_memalloc(sizeof(t_lst))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	return (new);
}

static int	strlen_del(t_lst *end, char **line, int ret, int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	if (ret == 0 && end->str[0] == '\0')
		return (0);
	while (end->str[len] != '\n' && end->str[len] != '\0')
		len++;
	if (end->str[len] == '\n')
	{
		*line = ft_strsub(end->str, 0, len);
		tmp = ft_strdup(end->str + len + 1);
		free(end->str);
		end->str = tmp;
	}
	else if (end->str[len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(end->str);
		ft_strdel(&end->str);
	}
	return (1);
}

t_lst		*find_or_create_fd(int fd, t_lst **lst)
{
	t_lst	*tmp;

	tmp = (*lst);
	if (tmp)
	{
		while (tmp->fd != fd && tmp != NULL)
		{
			if (tmp->next == NULL)
				tmp->next = create_lst(fd);
			tmp = tmp->next;
		}
	}
	else
	{
		(*lst) = create_lst(fd);
		return ((*lst));
	}
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static t_lst	*start;
	t_lst			*end;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || read(fd, buf, 0) < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	end = find_or_create_fd(fd, &start);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (end->str == NULL)
			end->str = ft_strnew(1);
		tmp = ft_strjoin(end->str, buf);
		free(end->str);
		end->str = tmp;
		if (ft_strchr(end->str, '\n') != NULL)
			break ;
	}
	if (ret == 0 && end->str == NULL)
		return (0);
	return (strlen_del(end, line, ret, fd));
}
