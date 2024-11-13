/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_display_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:25 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/13 15:31:26 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void display_ops(t_list *ops_list)
{
	t_list	*current;
	char	*ops_key[11];

	ops_key[0] = "sa";
	ops_key[1] = "sb";
	ops_key[2] = "ss";
	ops_key[3] = "pa";
	ops_key[4] = "pb";
	ops_key[5] = "ra";
	ops_key[6] = "rb";
	ops_key[7] = "rr";
	ops_key[8] = "rra";
	ops_key[9] = "rrb";
	ops_key[10] = "rrr";
	current = ops_list;
	while (current)
	{
		write(1, ops_key[current->num], ft_strlen(ops_key[current->num]));
		write(1, "\n", 1);
		current = current->next;
	}
}

static int pull_min_to_top(t_list **stack, unsigned int min, t_list **ops_list)
{
	unsigned int min_pos;
	t_list *min_node;
	unsigned int lst_size;

	min_node = *stack;
	min_pos = 0;
	while (min_node)
	{
		if (min_node->num == min)
			break ;
		min_pos++;
		min_node = min_node->next;
	}
	lst_size = ft_lstsize(*stack);
	if (min_pos <= lst_size / 2)
	{
		while (*stack != min_node)
			if (rotate(stack, 5, ops_list) == -1) // ra
				return (-1);
	}
	else
		while (*stack != min_node)
			if (reverse_rotate(stack, 8, ops_list) == -1) // rra
				return (-1);
	return (0);
}

static unsigned int find_min(t_list *stack)
{
	unsigned int	min;
	t_list			*current;

	min = UINT_MAX;
	current = stack;
	while (current)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}

// Modified selection sort
// mallocs a new list in which to save the operations
// at the end, optimizes the operations then frees the the malloced list
int	sort_and_display_ops(t_list **stack_a, t_list **stack_b)
{
	// while (stack_a || stack_a is unsorted)
		// Find smallest number (min_stack_a) in stack a
		// If min_stack_a is in the first half, ra until it is on top
		// else if min_stack_a is in the second half, rra until it is on top
			// if during the way, two consecutive numbers appear in the wrong order
			// swap them to correct the order
		// then push_b
	// while (stack_b)
		// push_a
	// call function to optimize the list of steps saved in a list
		// replace with ss, rr, rrr when necessary
		// remove neutral moves (e.g., pa + pb; sa + sa; ra + rra)
	// display the optimized list of operations
	// free the list of operations
	unsigned int min;
	t_list *ops_list;

	ops_list = NULL;
	while (!is_sorted(*stack_a) && *stack_a)
	{
		min = find_min(*stack_a);
		if (pull_min_to_top(stack_a, min, &ops_list) == -1)
			return (free_stack(&ops_list), -1);
		if (push(stack_a, stack_b, 4, &ops_list) == -1) // pb
			return (free_stack(&ops_list), -1);
	}
	while (*stack_b)
		if (push(stack_b, stack_a, 3, &ops_list) == -1) // pa
			return (free_stack(&ops_list), -1);
	replace_double_op(&ops_list);
	remove_neutral_ops(&ops_list);
	display_ops(ops_list);
	// check_print_list_exit(ops_list, *stack_b); // delete
	free_stack(&ops_list);
	return (0);
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