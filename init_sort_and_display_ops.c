/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort_and_display_ops.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:25 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/17 14:56:41 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_three(t_list **stack, t_list **ops_list)
{
	t_list	*max_node;
	int		status;

	status = 0;
	max_node = find_max_node(*stack);
	if (*stack == max_node)
		status = rotate(stack, 5, ops_list);
	else if ((*stack)->next == max_node)
		status = reverse_rotate(stack, 8, ops_list);
	if (status != -1 && (*stack)->num > (*stack)->next->num)
		status = swap(stack, 0, ops_list);
	return (status);
}

static int	perform_main_sort(t_list **stack_a, t_list **stack_b,
		t_list **ops_list, int size_a)
{
	int			status;
	t_rotations	best_move;

	status = 0;
	while (status != -1 && size_a-- > 3)
		status = push(stack_a, stack_b, 4, ops_list);
	if (status != -1)
		status = sort_three(stack_a, ops_list);
	while (status != -1 && *stack_b)
	{
		best_move = find_best_move(*stack_a, *stack_b, ft_lstsize(*stack_a),
				ft_lstsize(*stack_b));
		status = perform_best_move_rotations(stack_a, stack_b, ops_list,
				best_move);
		if (status != -1)
			status = push(stack_b, stack_a, 3, ops_list);
	}
	while (status != -1 && !is_sorted(*stack_a))
	{
		if (find_min_pos(*stack_a) <= ft_lstsize(*stack_a) / 2)
			status = rotate(stack_a, 5, ops_list);
		else if (status != -1)
			status = reverse_rotate(stack_a, 8, ops_list);
	}
	return (status);
}

int	sort_and_display_ops(t_list **stack_a, t_list **stack_b, int list_size)
{
	t_list	*ops_list;
	int		status;

	ops_list = NULL;
	status = 0;
	if (list_size == 2)
		status = swap(stack_a, 0, &ops_list);
	if (list_size > 2 && status != -1)
		status = perform_main_sort(stack_a, stack_b, &ops_list, list_size);
	if (status == -1)
		return (free_stack(&ops_list), -1);
	replace_double_op(&ops_list);
	remove_neutral_ops(&ops_list);
	display_ops(ops_list);
	free_stack(&ops_list);
	return (0);
}
