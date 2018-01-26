/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:03:11 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/19 19:16:25 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <fcntl.h>
# include <dirent.h>
# include <time.h>
# include "libft/libft.h"
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <string.h>
# include <errno.h>

typedef struct		s_stat
{
	struct s_stat	*next;
	char			*name;
	char			*path;
	dev_t			dev;
	char			*mode;
	mode_t			t_mode;
	char			*owner;
	char			*group;
	char			*last_mod;
	int				int_last_mod;
	int				directory;
	int				size;
	int				links;
	int				blocks;
}					t_stat;

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*children;
	struct s_stat	*files;
	char			*name;
	int				int_last_mod;
}					t_node;

typedef struct		s_options
{
	int				recur;
	int				r;
	int				l;
	int				a;
	int				t;
	int				total_blocks;
}					t_options;

void				merge_sort(t_stat **list, t_options *options);
t_stat				*sort_list(t_stat *left_half, t_stat *right_half,
		t_options *options);
void				split_list(t_stat *list, t_stat **left_half,
		t_stat **right_half);
void				merge_sort_dir(t_node **list, t_options *options);
t_node				*sort_list_dir(t_node *left_half, t_node *right_half,
		t_options *options);
void				split_list_dir(t_node *list, t_node **left_half,
		t_node **right_half);
t_node				*node_init(char *name, int int_last_mod);
t_stat				*stat_init(struct stat statbuf, char *name, char *path);
t_options			*init_options(void);
void				save_option(char c, t_options *option);
void				arg_files_list(char *arg, t_stat **arg_files,
		struct stat statbuf);
void				arg_dir_list(char *arg, t_node **arg_dir);
int					save_file_args(char *arg, t_stat **arg_files);
void				free_node(t_node *node, t_options *options);
void				check_for_options(char **argv, int *i, t_options *options);
char				*ft_itoa_base(unsigned int base, unsigned long val);
char				*translate_mode(char *mode, mode_t t_mode, t_stat *files);
void				add_children_to_node(t_node **node, char *name,
		struct stat statbuf);
void				add_file_to_node(t_node **node, struct stat statbuf,
		char *name, char *path);
void				print_sorted_files(t_stat *files, t_options *options);
void				print_dir_files(t_node *node, t_options *options);
void				print_args(t_stat *arg_files, t_node *arg_dir,
		t_options *options);
void				save_file_info(DIR *dir, t_node *node, t_options *options);
void				free_files(t_stat *files);
void				free_arg_dir(t_node *arg_dir, t_stat *arg_files,
		t_options *options);
#endif
