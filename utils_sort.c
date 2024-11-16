/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:01:50 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/16 17:06:10 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int find_min(t_list *stack)
// {
// 	int	min;
// 	t_list			*current;

// 	min = INT_MAX;
// 	current = stack;
// 	while (current)
// 	{
// 		if (current->num < min)
// 			min = current->num;
// 		current = current->next;
// 	}
// 	return (min);
// }

unsigned int find_min_pos(t_list *stack)
{
	unsigned int	i;
	int	min;
	unsigned int	min_pos;
	
	i = 0;
	min = UINT_MAX;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

t_list *find_max_node(t_list *stack)
{
	t_list *max;

	max = stack;
	while (stack)
	{
		if (max->num < stack->num)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
