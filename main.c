/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:35:36 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/19 17:42:59 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	save_file_info(DIR *dir, t_node *node, t_options *options)
{
	struct stat		statbuf;
	struct dirent	*dp;
	char			*file;

	while ((dp = readdir(dir)))
	{
		if (dp->d_name[0] == '.' && !options->a)
			continue ;
		file = ft_strjoinc(node->name, dp->d_name, '/');
		if (lstat(file, &statbuf) == -1)
		{
			free(file);
			ft_printf("Error: %s\n", strerror(errno));
			continue ;
		}
		options->total_blocks += statbuf.st_blocks;
		add_file_to_node(&node, statbuf, dp->d_name, file);
		free(file);
	}
}

void	save_args(char **argv, t_stat **arg_files, t_node **arg_dir, int i)
{
	while (argv[i])
	{
		if (save_file_args(argv[i], arg_files))
			i++;
		else
		{
			arg_dir_list(argv[i], arg_dir);
			i++;
		}
	}
}

void	free_arg_dir(t_node *arg_dir, t_stat *arg_files, t_options *options)
{
	t_node		*tmp;
	t_stat		*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	while (arg_dir)
	{
		tmp = arg_dir;
		arg_dir = arg_dir->next;
		free_node(tmp, options);
	}
	free_files(arg_files);
}

int		main(int argc, char **argv)
{
	int			i;
	t_node		*node;
	t_options	*options;
	t_stat		*arg_files;
	t_node		*arg_dir;

	i = 1;
	options = init_options();
	check_for_options(argv, &i, options);
	arg_files = NULL;
	arg_dir = NULL;
	if (!argv[i] || argc == 1)
	{
		node = node_init(".", 0);
		print_dir_files(node, options);
	}
	save_args(argv, &arg_files, &arg_dir, i);
	if (arg_files || arg_dir)
		print_args(arg_files, arg_dir, options);
	free(options);
	return (0);
}
