/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:04:04 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/18 10:48:57 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_both_up(t_list **stack_a, t_list **stack_b,
		t_list **ops_list, t_rotations best_move)
{
	int	status;

	status = 0;
	while (best_move.rotations_a > 0 && best_move.rotations_b > 0
		&& status != -1)
	{
		status = rotate(stack_a, 5, ops_list);
		if (status != -1)
			status = rotate(stack_b, 6, ops_list);
		best_move.rotations_a--;
		best_move.rotations_b--;
	}
	while (best_move.rotations_a-- > 0 && status != -1)
		status = rotate(stack_a, 5, ops_list);
	while (best_move.rotations_b-- > 0 && status != -1)
		status = rotate(stack_b, 6, ops_list);
	return (status);
}

static int	handle_both_down(t_list **stack_a, t_list **stack_b,
		t_list **ops_list, t_rotations best_move)
{
	int	status;

	status = 0;
	while (best_move.rotations_a > 0 && best_move.rotations_b > 0
		&& status != -1)
	{
		status = reverse_rotate(stack_a, 8, ops_list);
		if (status != -1)
			status = reverse_rotate(stack_b, 9, ops_list);
		best_move.rotations_a--;
		best_move.rotations_b--;
	}
	while (best_move.rotations_a-- > 0 && status != -1)
		status = reverse_rotate(stack_a, 8, ops_list);
	while (best_move.rotations_b-- > 0 && status != -1)
		status = reverse_rotate(stack_b, 9, ops_list);
	return (status);
}

static int	handle_different_directions(t_list **stack_a, t_list **stack_b,
		t_list **ops_list, t_rotations best_move)
{
	int	status;

	status = 0;
	if (best_move.direction_a == 'u' && status != -1)
		while (best_move.rotations_a-- > 0 && status != -1)
			status = rotate(stack_a, 5, ops_list);
	else
		while (best_move.rotations_a-- > 0 && status != -1)
			status = reverse_rotate(stack_a, 8, ops_list);
	if (best_move.direction_b == 'u' && status != -1)
		while (best_move.rotations_b-- > 0 && status != -1)
			status = rotate(stack_b, 6, ops_list);
	else
		while (best_move.rotations_b-- > 0 && status != -1)
			status = reverse_rotate(stack_b, 9, ops_list);
	return (status);
}

int	perform_best_move_rotations(t_list **stack_a, t_list **stack_b,
		t_list **ops_list, t_rotations best_move)
{
	if (best_move.direction_a == 'u' && best_move.direction_b == 'u')
		return (handle_both_up(stack_a, stack_b, ops_list, best_move));
	else if (best_move.direction_a == 'd' && best_move.direction_b == 'd')
		return (handle_both_down(stack_a, stack_b, ops_list, best_move));
	else
		return (handle_different_directions(stack_a, stack_b, ops_list,
				best_move));
	return (0);
}
