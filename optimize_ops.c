/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:38:47 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/16 15:39:23 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_neutral_op(int a, int b)
{
	if ((a == 0 && b == 0) || (a == 1 && b == 1) || (a == 2 && b == 2)
		|| (a == 3 && b == 4) || (a == 4 && b == 3) || (a == 5 && b == 8)
		|| (a == 6 && b == 9) || (a == 7 && b == 10) || (a == 8 && b == 5)
		|| (a == 9 && b == 6) || (a == 10 && b == 7))
		return (1);
	return (0);
}

void	remove_neutral_ops(t_list **ops_list)
{
	t_list	*current;
	t_list	*temp;

	current = *ops_list;
	if (!current || !current->next)
		return ;
	while (current->next->next)
	{
		if (is_neutral_op(current->next->num, current->next->next->num))
		{
			temp = current->next->next->next;
			free(current->next->next);
			free(current->next);
			current->next = temp;
			if (!current || !current->next)
				break ;
			continue ;
		}
		current = current->next;
		if (!current || !current->next)
			break ;
	}
	if (current && current->next && is_neutral_op(current->num,
			current->next->num))
	{
		*ops_list = NULL;
		free(current->next);
		free(current);
	}
}

static void	del_next_change_num(t_list *current, int num)
{
	t_list	*temp;

	temp = current->next->next;
	free(current->next);
	current->next = temp;
	current->num = num;
}

void	replace_double_op(t_list **ops_list)
{
	t_list	*current;

	current = *ops_list;
	if (!current)
		return ;
	while (current->next)
	{
		if (current->num == 0 && current->next->num == 1)
			del_next_change_num(current, 2);
		else if (current->num == 5 && current->next->num == 6)
			del_next_change_num(current, 7);
		else if (current->num == 8 && current->next->num == 9)
			del_next_change_num(current, 10);
		current = current->next;
	}
}
