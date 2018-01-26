/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:35:36 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/07 13:17:19 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node		*node_init(char *name, int int_last_mod)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new->next = NULL;
	new->children = NULL;
	new->files = NULL;
	new->name = ft_strdup(name);
	new->int_last_mod = int_last_mod;
	return (new);
}

t_stat		*stat_init(struct stat statbuf, char *name, char *path)
{
	t_stat			*new;
	struct passwd	*pwd;
	struct group	*grp;

	new = (t_stat*)ft_memalloc(sizeof(t_stat));
	new->next = NULL;
	new->name = ft_strdup(name);
	new->path = ft_strdup(path);
	new->dev = statbuf.st_rdev;
	new->mode = ft_itoa_base(8, statbuf.st_mode);
	new->t_mode = statbuf.st_mode;
	if ((pwd = getpwuid(statbuf.st_uid)))
		new->owner = ft_strdup(pwd->pw_name);
	if ((grp = getgrgid(statbuf.st_gid)))
		new->group = ft_strdup(grp->gr_name);
	new->int_last_mod = statbuf.st_mtime;
	new->last_mod = ft_strdup(ctime(&statbuf.st_mtime) + 4);
	if (S_ISDIR(statbuf.st_mode))
		new->directory = 1;
	new->size = statbuf.st_size;
	new->links = statbuf.st_nlink;
	new->blocks = statbuf.st_blocks;
	return (new);
}

t_options	*init_options(void)
{
	t_options *new;

	new = (t_options*)ft_memalloc(sizeof(t_options));
	return (new);
}

void		save_option(char c, t_options *option)
{
	c == 'r' ? option->r = 1 : 0;
	c == 'R' ? option->recur = 1 : 0;
	c == 'l' ? option->l = 1 : 0;
	c == 'a' ? option->a = 1 : 0;
	c == 't' ? option->t = 1 : 0;
}
