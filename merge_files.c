/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:35:36 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/07 17:09:30 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	split_list(t_stat *list, t_stat **left_half, t_stat **right_half)
{
	t_stat	*middle;
	t_stat	*end;

	middle = list;
	end = list->next;
	if (!list || !list->next)
	{
		middle = list;
		end = NULL;
		return ;
	}
	while (end)
	{
		end = end->next;
		if (end)
		{
			middle = middle->next;
			end = end->next;
		}
	}
	*left_half = list;
	*right_half = middle->next;
	middle->next = NULL;
}

t_stat	*sort_by_time(t_stat *left_half, t_stat *right_half, t_options *options)
{
	t_stat *result;

	result = NULL;
	if (!left_half)
		return (right_half);
	if (!right_half)
		return (left_half);
	if ((!options->r && left_half->int_last_mod >= right_half->int_last_mod) ||
			(options->r && left_half->int_last_mod <= right_half->int_last_mod))
	{
		result = left_half;
		result->next = sort_by_time(left_half->next, right_half, options);
	}
	else
	{
		result = right_half;
		result->next = sort_by_time(left_half, right_half->next, options);
	}
	return (result);
}

t_stat	*sort_list(t_stat *left_half, t_stat *right_half, t_options *options)
{
	t_stat	*result;
	int		i;

	i = 0;
	result = NULL;
	if (!left_half)
		return (right_half);
	if (!right_half)
		return (left_half);
	while (left_half->name[i] == right_half->name[i])
		i++;
	if ((options->r && left_half->name[i] >= right_half->name[i]) ||
			(!options->r && left_half->name[i] <= right_half->name[i]))
	{
		result = left_half;
		result->next = sort_list(left_half->next, right_half, options);
	}
	else
	{
		result = right_half;
		result->next = sort_list(left_half, right_half->next, options);
	}
	return (result);
}

void	merge_sort(t_stat **list, t_options *options)
{
	t_stat	*head;
	t_stat	*left_half;
	t_stat	*right_half;

	head = *list;
	if (!head || !head->next)
		return ;
	split_list(head, &left_half, &right_half);
	merge_sort(&left_half, options);
	merge_sort(&right_half, options);
	if (!options->t)
		*list = sort_list(left_half, right_half, options);
	else
		*list = sort_by_time(left_half, right_half, options);
}
