/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:04:23 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/06 22:43:43 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_children_to_node(t_node **node, char *name, struct stat statbuf)
{
	t_node	*tmp;
	char	*path;

	tmp = (*node)->children;
	if (ft_strequ(name, ".") || ft_strequ(name, ".."))
		return ;
	path = ft_strjoinc((*node)->name, name, '/');
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node_init(path, statbuf.st_mtime);
	}
	else
		(*node)->children = node_init(path, statbuf.st_mtime);
	free(path);
}

void	add_file_to_node(t_node **node, struct stat statbuf, char *name,
		char *path)
{
	t_stat *tmp;

	tmp = (*node)->files;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stat_init(statbuf, name, path);
	}
	else
		(*node)->files = stat_init(statbuf, name, path);
	if (S_ISDIR(statbuf.st_mode))
		add_children_to_node(node, name, statbuf);
}
