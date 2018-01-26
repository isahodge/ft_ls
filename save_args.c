/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:35:36 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/09 20:35:52 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_for_options(char **argv, int *i, t_options *options)
{
	int j;

	j = 1;
	while (argv[*i] && argv[*i][0] == '-')
	{
		while (argv[*i][j])
		{
			if (argv[*i][j] == 'R' || argv[*i][j] == 'r' || argv[*i][j] == 'l'
					|| argv[*i][j] == 'a' | argv[*i][j] == 't')
				save_option(argv[*i][j], options);
			else
			{
				ft_putstr("ft_ls: illegal option\nusage: ./ft_ls [-Ralrt] ");
				ft_putstr("[file ...]\n");
				exit(1);
			}
			j++;
		}
		(*i)++;
		j = 1;
	}
}

int		save_file_args(char *arg, t_stat **arg_files)
{
	struct stat		statbuf;

	if (lstat(arg, &statbuf) == -1)
	{
		ft_printf("./ft_ls: %s: %s\n", arg, strerror(errno));
		return (-1);
	}
	if (S_ISREG(statbuf.st_mode))
	{
		arg_files_list(arg, arg_files, statbuf);
		return (1);
	}
	else if (S_ISDIR(statbuf.st_mode))
		return (0);
	ft_printf("./ft_ls: %s: No such file or directory\n", arg);
	return (1);
}

void	arg_files_list(char *arg, t_stat **arg_files, struct stat statbuf)
{
	t_stat *tmp;

	tmp = (*arg_files);
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stat_init(statbuf, arg, arg);
	}
	else
		(*arg_files) = stat_init(statbuf, arg, arg);
}

void	arg_dir_list(char *arg, t_node **arg_dir)
{
	t_node		*tmp;
	struct stat	statbuf;

	tmp = (*arg_dir);
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		lstat(arg, &statbuf);
		tmp->next = node_init(arg, (int)statbuf.st_mtime);
	}
	else
	{
		lstat(arg, &statbuf);
		(*arg_dir) = node_init(arg, (int)statbuf.st_mtime);
	}
}
