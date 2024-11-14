/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_display_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:25 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/14 20:09:50 by anaqvi           ###   ########.fr       */
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

static int pull_min_to_top(t_list **stack, unsigned int min, t_list **ops_list, unsigned int list_size)
{
	unsigned int min_pos;
	t_list *min_node;
	min_node = *stack;
	min_pos = 0;
	int status;

	while (min_node)
	{
		if (min_node->num == min)
			break ;
		min_pos++;
		min_node = min_node->next;
	}
	if (min_pos <= list_size / 2)
	{
		while (*stack != min_node)
		{
			if ((*stack)->num == ((*stack)->num) + 1) // or swap always when wrong order
				status = swap(stack, 0, ops_list);
			else
				status = rotate(stack, 5, ops_list); // ra
		}
	}
	else
		while (*stack != min_node)
		{
			if ((*stack)->num == ((*stack)->num) + 1)
				status = swap(stack, 0, ops_list);
			else
				status = reverse_rotate(stack, 8, ops_list); // rra
		}
	return (status);
}

static int pull_max_to_top(t_list **stack, unsigned int max, t_list **ops_list, unsigned int list_size)
{
	unsigned int max_pos;
	t_list *max_node;
	max_node = *stack;
	max_pos = 0;
	int status;

	while (max_node)
	{
		if (max_node->num == max)
			break ;
		max_pos++;
		max_node = max_node->next;
	}
	if (max_pos <= list_size / 2)
	{
		while (*stack != max_node)
		{
			// if ((*stack)->num == ((*stack)->num) + 1) // or swap always when wrong order
			// 	status = swap(stack, 0, ops_list);
			// else
				status = rotate(stack, 6, ops_list); // ra
		}
	}
	else
		while (*stack != max_node)
		{
			// if ((*stack)->num == ((*stack)->num) + 1)
			// 	status = swap(stack, 0, ops_list);
			// else
				status = reverse_rotate(stack, 9, ops_list); // rra
		}
	return (status);
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

static unsigned int find_max(t_list *stack)
{
	unsigned int	max;
	t_list			*current;

	max = 0;
	current = stack;
	while (current)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
	}
	return (max);
}

static int contains_other_chunks(t_list *stack, unsigned int cutoff)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->num <= cutoff)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int divide_hi_mid_lo(t_list **stack_a, t_list **stack_b, t_list **ops_list, unsigned int list_size)
{
	unsigned int	cutoff_1;
	unsigned int	cutoff_2;
	int				status;
	
	if (list_size < 6)
		return (0);
	cutoff_1 = (list_size / 3) - 1;
	cutoff_2 = cutoff_1 + (list_size / 3);
	while (!is_sorted(*stack_a) && contains_other_chunks(*stack_a, cutoff_2))
	{
		if (status == -1)
			return (-1);
		if ((*stack_a)->num > cutoff_2)
		{
			if ((*stack_a)->next->num > cutoff_2 && (*stack_a)->next->num < (*stack_a)->num)
				status = swap(stack_a, 0, ops_list);
			else
				status = rotate(stack_a, 5, ops_list);
		}
		else if ((*stack_a)->num > cutoff_1 && (*stack_a)->num <= cutoff_2)
		{
			if ((*stack_a)->num > cutoff_1 && (*stack_a)->num <= cutoff_2 && (*stack_a)->next->num < (*stack_a)->num)
				status = swap(stack_a, 0, ops_list);
			else
				status = push(stack_a, stack_b, 4, ops_list);
		}
		else if ((*stack_a)->num <= cutoff_1)
		{
			if ((*stack_a)->num <= cutoff_1 && (*stack_a)->next->num < (*stack_a)->num)
				status = swap(stack_a, 0, ops_list);
			else
			{
				status = push(stack_a, stack_b, 4, ops_list);
				if (status =! -1 && ft_lstsize(*stack_b) > 1)
					status = rotate(stack_b, 6, ops_list);
			}
		}
	}
	return (status);
}

int	sort_and_display_ops(t_list **stack_a, t_list **stack_b, unsigned int list_size)
{
	unsigned int min;
	unsigned int max;
	t_list *ops_list;

	ops_list = NULL;
	if (divide_hi_mid_lo(stack_a, stack_b, &ops_list, list_size) == -1)
		return (free_stack(&ops_list), -1);
	while (!is_sorted(*stack_a) && *stack_a)
	{
		min = find_min(*stack_a);
		if (pull_min_to_top(stack_a, min, &ops_list, list_size) == -1)
			return (free_stack(&ops_list), -1);
		if (push(stack_a, stack_b, 4, &ops_list) == -1) // pb
			return (free_stack(&ops_list), -1);
	}
	while (*stack_b)
	{
		max = find_max(*stack_b);
		if (pull_max_to_top(stack_b, max, &ops_list, list_size) == -1)
			return (free_stack(&ops_list), -1);
		if (push(stack_b, stack_a, 3, &ops_list) == -1) // pb
			return (free_stack(&ops_list), -1);
	}
	// check_print_list_exit(*stack_a, *stack_b); // delete
	replace_double_op(&ops_list);
	remove_neutral_ops(&ops_list);
	display_ops(ops_list);
	free_stack(&ops_list);
	return (0);
}
