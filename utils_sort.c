/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:16:10 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/17 11:45:02 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_pos(t_list *stack)
{
	int	i;
	int	min;
	int	min_pos;
	
	i = 0;
	min = INT_MAX;
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
