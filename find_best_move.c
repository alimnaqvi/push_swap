/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:58:31 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/17 15:02:46 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_rotts(int pos, int size, int *rotations,
		char *direction)
{
	if (pos <= size / 2)
	{
		*rotations = pos;
		*direction = 'u';
	}
	else
	{
		*rotations = size - pos;
		*direction = 'd';
	}
}

static int	get_target_position_in_a(t_list *stack_a, int value)
{
	int		i;
	t_list	*current;
	int		size;
	int		prev_value;
	int		curr_value;

	current = stack_a;
	if (!stack_a)
		return (0);
	size = ft_lstsize(stack_a);
	prev_value = stack_a->num;
	current = stack_a->next;
	i = 1;
	while (i <= size)
	{
		curr_value = current ? current->num : stack_a->num;
		if ((value > prev_value && value < curr_value)
			|| (prev_value > curr_value && (value > prev_value
					|| value < curr_value)))
			return (i % size);
		prev_value = curr_value;
		current = current ? current->next : NULL;
		i++;
	}
	return (find_min_pos(stack_a));
}

t_rotations	find_best_move(t_list *stack_a, t_list *stack_b, int size_a,
		int size_b)
{
	t_rotations	best_move;
	t_rotations	move;
	int			pos_b;

	pos_b = 0;
	best_move.total_moves = INT_MAX;
	while (stack_b)
	{
		move.value = stack_b->num;
		move.pos_b = pos_b;
		compute_rotts(pos_b++, size_b, &move.rotations_b,
			&move.direction_b);
		move.pos_a = get_target_position_in_a(stack_a, move.value);
		compute_rotts(move.pos_a, size_a, &move.rotations_a, &move.direction_a);
		if (move.direction_a == 'u' && move.direction_b == 'u')
			move.total_moves = MAX(move.rotations_a, move.rotations_b);
		else if (move.direction_a == 'd' && move.direction_b == 'd')
			move.total_moves = MAX(move.rotations_a, move.rotations_b);
		else
			move.total_moves = move.rotations_a + move.rotations_b;
		if (move.total_moves < best_move.total_moves)
			best_move = move;
		stack_b = stack_b->next;
	}
	return (best_move);
}
