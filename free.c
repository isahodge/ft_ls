/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:35:36 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/09 20:22:49 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_files(t_stat *files)
{
	t_stat *tmp;

	tmp = NULL;
	while (files)
	{
		tmp = files;
		files = files->next;
		tmp->name ? free(tmp->name) : 0;
		tmp->path ? free(tmp->path) : 0;
		tmp->mode ? free(tmp->mode) : 0;
		tmp->owner ? free(tmp->owner) : 0;
		tmp->group ? free(tmp->group) : 0;
		tmp->last_mod ? free(tmp->last_mod) : 0;
		free(tmp);
	}
}

void	free_node(t_node *node, t_options *options)
{
	t_node *children;

	if (node)
	{
		node->files ? free_files(node->files) : 0;
		children = node->children;
		while (node->children && !options->recur)
		{
			node->children = node->children->next;
			free(children->name);
			free(children);
			children = node->children;
		}
		free(node->name);
		free(node);
		node = NULL;
	}
}
