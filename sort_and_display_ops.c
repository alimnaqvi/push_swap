/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_display_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:25 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/12 19:59:05 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find smallest in stack a then push to stack b
// mallocs a new list in which to save the operations
// at the end, optimizes the operations then frees the the malloced list
int	sort_and_display_ops(t_list **stack_a, t_list **stack_b)
{
	// while (stack_a || stack_a is unsorted)
		// Find smallest number (min_stack_a) in stack a
		// If min_stack_a is in the first half, ra until it is on top
		// else if min_stack_a is in the second half, rra until it is on top
		// then push_b
	// while (stack_b)
		// push_a
	// call function to optimize the list of steps saved in a list
		// replace with ss, rr, rrr when necessary
		// remove neutral moves (e.g., pa + pb; sa + sa; ra + rra)
	// display the optimized list of operations
	// free the list of operations
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