/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_display_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:25 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/12 19:11:25 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_and_display_ops(t_list **stack_a, t_list **stack_b)
{
	//
}

// Initial bubble sort
/*
int	sort_and_display_ops(t_list **stack_a, t_list **stack_b)
{
	while (!is_sorted(*stack_a) || *stack_b)
	{
		while (*stack_a)
		{
			if ((*stack_a)->next && (*stack_a)->num > (*stack_a)->next->num)
				swap(stack_a, "sa");
			push(stack_a, stack_b, "pb");
		}
		while (*stack_b)
		{
			if ((*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
				swap(stack_b, "sb");
			push(stack_b, stack_a, "pa");
		}
	}
	return (0);
}
*/