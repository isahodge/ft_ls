/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihodge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:35:36 by ihodge            #+#    #+#             */
/*   Updated: 2018/01/07 17:03:39 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	split_list_dir(t_node *list, t_node **left_half, t_node **right_half)
{
	t_node	*middle;
	t_node	*end;

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

t_node	*sort_dir_time(t_node *left_half, t_node *right_half,
		t_options *options)
{
	t_node *result;

	result = NULL;
	if (!left_half)
		return (right_half);
	if (!right_half)
		return (left_half);
	if ((!options->r && left_half->int_last_mod >= right_half->int_last_mod) ||
		(options->r && left_half->int_last_mod <= right_half->int_last_mod))
	{
		result = left_half;
		result->next = sort_list_dir(left_half->next, right_half, options);
	}
	else
	{
		result = right_half;
		result->next = sort_list_dir(left_half, right_half->next, options);
	}
	return (result);
}

t_node	*sort_list_dir(t_node *left_half, t_node *right_half,
		t_options *options)
{
	t_node	*result;
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
		result->next = sort_list_dir(left_half->next, right_half, options);
	}
	else
	{
		result = right_half;
		result->next = sort_list_dir(left_half, right_half->next, options);
	}
	return (result);
}

void	merge_sort_dir(t_node **list, t_options *options)
{
	t_node	*head;
	t_node	*left_half;
	t_node	*right_half;

	head = *list;
	if (!head || !head->next)
		return ;
	split_list_dir(head, &left_half, &right_half);
	merge_sort_dir(&left_half, options);
	merge_sort_dir(&right_half, options);
	if (!options->t)
		*list = sort_list_dir(left_half, right_half, options);
	else
		*list = sort_dir_time(left_half, right_half, options);
}
