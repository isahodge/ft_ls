/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:13:47 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/19 18:42:05 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_dir_files(t_node *node, t_options *opt)
{
	DIR				*dir;

	dir = opendir(node->name);
	dir ? save_file_info(dir, node, opt) :
		ft_printf("./ft_ls: %s: %s\n", node->name, strerror(errno));
	opt->l && node->files ? ft_printf("total %i\n", opt->total_blocks) : 0;
	merge_sort(&node->files, opt);
	dir ? print_sorted_files(node->files, opt) : 0;
	merge_sort_dir(&node->children, opt);
	if ((node->children && opt->recur) &&
			ft_printf("\n%s:\n", node->children->name))
		print_dir_files(node->children, opt);
	if ((node->next && opt->recur) && ft_printf("\n%s:\n", node->next->name))
		print_dir_files(node->next, opt);
	dir ? closedir(dir) : 0;
	node ? free_node(node, opt) : 0;
}

char	*print_link(t_stat *files)
{
	char	buf[100];
	int		len;
	char	*new;
	char	*new2;

	if (S_ISLNK(files->t_mode))
	{
		if ((len = readlink(files->path, buf, sizeof(buf) - 1)) != -1)
		{
			buf[len] = '\0';
			new = ft_strjoin(files->name, " -> ");
			new2 = ft_strjoin(new, buf);
			free(new);
			return (new2);
		}
	}
	return (ft_strdup(files->name));
}

void	long_print(t_stat *files, char *link, char *mode)
{
	char	*date;
	char	*year;

	year = ft_strsub(files->last_mod, 15, 5);
	if (time(NULL) - files->int_last_mod > 15800000)
	{
		date = (char *)ft_memalloc(20);
		ft_strncpy(date, files->last_mod, 6);
		ft_strcat(date, year);
	}
	else
		date = ft_strdup(files->last_mod);
	if (S_ISCHR(files->t_mode) || S_ISBLK(files->t_mode))
		ft_printf("%-7s %-3i %-10s %-15s %3u, %10i %.12s %s\n", mode,
				files->links, files->owner, files->group,
				major(files->dev), (unsigned int)minor(files->dev),
				date, files->name);
	else
		ft_printf("%-7s %-3i %-10s %-15s      %10i %.12s %s\n", mode,
				files->links, files->owner, files->group, files->size,
				date, link);
	free(date);
	free(year);
}

void	print_sorted_files(t_stat *files, t_options *options)
{
	char	*mode;
	char	*link;
	t_stat	*tmp;

	options->total_blocks = 0;
	tmp = files;
	while (tmp)
	{
		if (options->l)
		{
			mode = translate_mode(tmp->mode, tmp->t_mode, files);
			link = print_link(tmp);
			long_print(tmp, link, mode);
			free(mode);
			free(link);
		}
		else
			ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

void	print_args(t_stat *arg_files, t_node *arg_dir, t_options *options)
{
	int		print_dir_name;
	t_node	*node;
	t_node	*tmp;

	node = NULL;
	print_dir_name = 0;
	merge_sort(&arg_files, options);
	print_sorted_files(arg_files, options);
	if (arg_files && arg_dir)
		ft_putchar('\n');
	merge_sort_dir(&arg_dir, options);
	if (arg_files || arg_dir->next)
		print_dir_name = 1;
	tmp = arg_dir;
	while (tmp)
	{
		if (print_dir_name)
			ft_printf("%s:\n", tmp->name);
		node = node_init(tmp->name, tmp->int_last_mod);
		print_dir_files(node, options);
		if (tmp->next)
			ft_putstr("\n");
		tmp = tmp->next;
	}
	free_arg_dir(arg_dir, arg_files, options);
}
