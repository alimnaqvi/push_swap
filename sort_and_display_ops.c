/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_display_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:25 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/15 16:50:38 by anaqvi           ###   ########.fr       */
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

// static int pull_min_to_top(t_list **stack, unsigned int min, t_list **ops_list, unsigned int list_size)
// {
// 	unsigned int min_pos;
// 	t_list *min_node;
// 	int status;

// 	min_node = *stack;
// 	min_pos = 0;
// 	while (min_node)
// 	{
// 		if (min_node->num == min)
// 			break ;
// 		min_pos++;
// 		min_node = min_node->next;
// 	}
// 	if (min_pos <= list_size / 2)
// 	{
// 		while (*stack != min_node)
// 		{
// 			if ((*stack)->num == ((*stack)->num) + 1) // or swap always when wrong order
// 				status = swap(stack, 0, ops_list);
// 			else
// 				status = rotate(stack, 5, ops_list); // ra
// 		}
// 	}
// 	else
// 		while (*stack != min_node)
// 		{
// 			if ((*stack)->num == ((*stack)->num) + 1)
// 				status = swap(stack, 0, ops_list);
// 			else
// 				status = reverse_rotate(stack, 8, ops_list); // rra
// 		}
// 	return (status);
// }

// static int pull_max_to_top(t_list **stack, unsigned int max, t_list **ops_list, unsigned int list_size)
// {
// 	unsigned int max_pos;
// 	t_list *max_node;
// 	max_node = *stack;
// 	max_pos = 0;
// 	int status;

// 	while (max_node)
// 	{
// 		if (max_node->num == max)
// 			break ;
// 		max_pos++;
// 		max_node = max_node->next;
// 	}
// 	if (max_pos <= list_size / 2)
// 	{
// 		while (*stack != max_node)
// 		{
// 			// if ((*stack)->num == ((*stack)->num) + 1) // or swap always when wrong order
// 			// 	status = swap(stack, 0, ops_list);
// 			// else
// 				status = rotate(stack, 6, ops_list); // ra
// 		}
// 	}
// 	else
// 		while (*stack != max_node)
// 		{
// 			// if ((*stack)->num == ((*stack)->num) + 1)
// 			// 	status = swap(stack, 0, ops_list);
// 			// else
// 				status = reverse_rotate(stack, 9, ops_list); // rra
// 		}
// 	return (status);
// }

// static unsigned int find_min(t_list *stack)
// {
// 	unsigned int	min;
// 	t_list			*current;

// 	min = UINT_MAX;
// 	current = stack;
// 	while (current)
// 	{
// 		if (current->num < min)
// 			min = current->num;
// 		current = current->next;
// 	}
// 	return (min);
// }

// static unsigned int find_max(t_list *stack)
// {
// 	unsigned int	max;
// 	t_list			*current;

// 	max = 0;
// 	current = stack;
// 	while (current)
// 	{
// 		if (current->num > max)
// 			max = current->num;
// 		current = current->next;
// 	}
// 	return (max);
// }

// static int contains_other_chunks(t_list *stack, unsigned int cutoff)
// {
// 	if (!stack)
// 		return (0);
// 	while (stack)
// 	{
// 		if (stack->num <= cutoff)
// 			return (1);
// 		stack = stack->next;
// 	}
// 	return (0);
// }

// static int divide_hi_mid_lo(t_list **stack_a, t_list **stack_b, t_list **ops_list, unsigned int list_size)
// {
// 	unsigned int	cutoff_1;
// 	unsigned int	cutoff_2;
// 	int				status;
	
// 	if (list_size < 6)
// 		return (0);
// 	cutoff_1 = (list_size / 3) - 1;
// 	cutoff_2 = cutoff_1 + (list_size / 3);
// 	while (!is_sorted(*stack_a) && contains_other_chunks(*stack_a, cutoff_2))
// 	{
// 		if (status == -1)
// 			return (-1);
// 		if ((*stack_a)->num > cutoff_2)
// 		{
// 			if ((*stack_a)->next->num > cutoff_2 && (*stack_a)->next->num < (*stack_a)->num)
// 				status = swap(stack_a, 0, ops_list);
// 			else
// 				status = rotate(stack_a, 5, ops_list);
// 		}
// 		else if ((*stack_a)->num > cutoff_1 && (*stack_a)->num <= cutoff_2)
// 		{
// 			if ((*stack_a)->num > cutoff_1 && (*stack_a)->num <= cutoff_2 && (*stack_a)->next->num < (*stack_a)->num)
// 				status = swap(stack_a, 0, ops_list);
// 			else
// 				status = push(stack_a, stack_b, 4, ops_list);
// 		}
// 		else if ((*stack_a)->num <= cutoff_1)
// 		{
// 			if ((*stack_a)->num <= cutoff_1 && (*stack_a)->next->num < (*stack_a)->num)
// 				status = swap(stack_a, 0, ops_list);
// 			else
// 			{
// 				status = push(stack_a, stack_b, 4, ops_list);
// 				if (status =! -1 && ft_lstsize(*stack_b) > 1)
// 					status = rotate(stack_b, 6, ops_list);
// 			}
// 		}
// 	}
// 	return (status);
// }

// static int find_best_in_a_and_rotate(t_list **stack_a, t_list **stack_b, t_list **ops_list, unsigned int list_size)
// {
// 	unsigned int i;
// 	unsigned int best_pos;
// 	unsigned int best_num;
// 	unsigned int next_smallest_pos;
// 	unsigned int moves_to_bring_top;
// 	t_list *current;

// 	best_pos = 0;
// 	best_num = (*stack_a)->num;
// 	next_smallest_pos = find_next_smallest_pos(*stack_b, best_num); // if best_num is larger or smaller than all nums in stack b, this should return either the largest or smallest pos in b, whichever is close at hand
// 	moves_to_bring_top = calc_moves_to_bring_top(*stack_b, next_smallest_pos);
// 	if (best_pos == 0 && moves_to_bring_top == 0)
// 		return (0);
// 	i = 0;
// 	current = *stack_a;
// 	while (current)
// 	{
// 		best_num = current->num;
// 		next_smallest_pos = find_next_smallest_pos(*stack_b, best_num);
// 		moves_to_bring_top = calc_moves_to_bring_top(*stack_b, next_smallest_pos);
// 		//
// 		current = current->next;
// 		i++;
// 	}
// }

// static int sort_three(t_list **stack, t_list **ops_list)
// {
// 	int		status;
// 	t_list	*pos1;
// 	t_list	*pos2;
// 	t_list	*pos3;
	
// 	status = 0;
// 	pos1 = *stack;
// 	pos2 = pos1->next;
// 	pos3 = pos2->next;
// 	if (is_sorted(*stack)) // case 1-2-3
// 		return (0);
// 	if (pos1->num < pos2->num && pos3->num < pos1->num) // case 2-3-1
// 		return (reverse_rotate(stack, 5, ops_list));  // ra
// 	if (pos1->num > pos3->num && pos3->num > pos2->num) // case 3-1-2
// 		return (rotate(stack, 5, ops_list));  // ra
// 	if (pos1->num > pos3->num && pos1->num > pos2->num) // case 2-1-3
// 		return (swap(stack, 0, ops_list));  // sa
// 	if (pos1->num > pos2->num && pos2->num > pos1->num) // case 3-2-1
// 	{
// 		status = rotate(stack, 5, ops_list); // ra
// 		if (status != -1)
// 			status = swap(stack, 0, ops_list); // sa
// 		return (status);
// 	}
// 	if (pos1->num < pos3->num && pos3->num < pos2->num) // case 1-3-2
// 	{
// 		status = reverse_rotate(stack, 8, ops_list); // rra
// 		if (status != -1)
// 			status = swap(stack, 0, ops_list); // sa
// 		return (status);
// 	}
// }

static int sort_three(t_list **stack, t_list **ops_list)
{
    int     status;
    int     first, second, third;

    status = 0;
    first = (*stack)->num;
    second = (*stack)->next->num;
    third = (*stack)->next->next->num;

    if (is_sorted(*stack)) // Case: A < B < C
        return (0);

    if (first > second && second < third && first < third)
    {
        // Case: B, A, C -> Swap first two
        return (swap(stack, 0, ops_list)); // sa
    }

    if (first > second && second > third)
    {
        // Case: C, B, A -> Swap first two and reverse rotate
        status = swap(stack, 0, ops_list); // sa
        if (status != -1)
            status = reverse_rotate(stack, 8, ops_list); // rra
        return (status);
    }

    if (first > second && second < third && first > third)
    {
        // Case: C, A, B -> Rotate
        return (rotate(stack, 5, ops_list)); // ra
    }

    if (first < second && second > third && first < third)
    {
        // Case: A, C, B -> Reverse rotate and swap
        status = reverse_rotate(stack, 8, ops_list); // rra
        if (status != -1)
            status = swap(stack, 0, ops_list); // sa
        return (status);
    }

    if (first < second && second > third && first > third)
    {
        // Case: B, C, A -> Reverse rotate
        return (reverse_rotate(stack, 8, ops_list)); // rra
    }

    // If none of the above conditions are met, return an error or handle accordingly
    return (-1);
}

static unsigned int find_min_pos(t_list *stack)
{
	unsigned int	i;
	unsigned int	min;
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

int	sort_and_display_ops(t_list **stack_a, t_list **stack_b, unsigned int list_size)
{
	unsigned int min;
	unsigned int max;
	unsigned int min_pos;
	t_list *ops_list;
	int status;

	ops_list = NULL;
	status = 0;
	while (status != -1 && ft_lstsize(*stack_b) <= 2 && ft_lstsize(*stack_a) > 3)
		status = push(stack_a, stack_b, 4, &ops_list); // pb
	while (status != -1 && ft_lstsize(*stack_a) > 3)
	{
		status = find_best_in_a_and_rotate(stack_a, stack_b, &ops_list, list_size);
		if (status != -1)
			status = push(stack_a, stack_b, 4, &ops_list); // pb
	}
	if (status != -1)
		status = sort_three(stack_a, &ops_list);
	while (status != -1 && *stack_b)
	{
		status = find_best_in_b_and_rotate(stack_b, stack_a, &ops_list, list_size);
		if (status != -1)
			status = push(stack_b, stack_a, 3, &ops_list);  // pa
	}
	min_pos = find_min_pos(*stack_a);
	while (status != -1 && !is_sorted(*stack_a))
	{
		if (min_pos <= list_size / 2)
			status = rotate(stack_a, 5, &ops_list);
		else if (status != -1)
			status = reverse_rotate(stack_a, 8, &ops_list);
	}
	if (status == -1)
		return (free_stack(&ops_list), -1);
	//
	// if (divide_hi_mid_lo(stack_a, stack_b, &ops_list, list_size) == -1)
	// 	return (free_stack(&ops_list), -1);
	// while (!is_sorted(*stack_a) && *stack_a)
	// {
	// 	min = find_min(*stack_a);
	// 	if (pull_min_to_top(stack_a, min, &ops_list, list_size) == -1)
	// 		return (free_stack(&ops_list), -1);
	// 	if (push(stack_a, stack_b, 4, &ops_list) == -1) // pb
	// 		return (free_stack(&ops_list), -1);
	// }
	// while (*stack_b)
	// {
	// 	max = find_max(*stack_b);
	// 	if (pull_max_to_top(stack_b, max, &ops_list, list_size) == -1)
	// 		return (free_stack(&ops_list), -1);
	// 	if (push(stack_b, stack_a, 3, &ops_list) == -1) // pa
	// 		return (free_stack(&ops_list), -1);
	// }
	// check_print_list_exit(*stack_a, *stack_b); // delete
	replace_double_op(&ops_list);
	remove_neutral_ops(&ops_list);
	display_ops(ops_list);
	free_stack(&ops_list);
	return (0);
}
