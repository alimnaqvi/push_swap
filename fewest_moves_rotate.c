/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewest_moves_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:58:31 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/17 11:58:27 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void compute_rotations(int pos, int size, int *rotations, char *direction)
{
    if (pos <= size / 2)
    {
        *rotations = pos;
        *direction = 'u'; // up, rotate
    }
    else
    {
        *rotations = size - pos;
        *direction = 'd'; // down, reverse rotate
    }
}

int get_target_position_in_a(t_list *stack_a, int value)
{
    int i;
    t_list *current;
    int size;
    int prev_value;
    int curr_value;

    current = stack_a;

    if (!stack_a)
        return 0;

    size = ft_lstsize(stack_a);
    prev_value = stack_a->num;
    current = stack_a->next;

    i = 1;
    while (i <= size)
    {
        curr_value = current ? current->num : stack_a->num;
        if ((value > prev_value && value < curr_value) ||
            (prev_value > curr_value && (value > prev_value || value < curr_value)))
        {
            // Found the right position
            return (i % size);
        }
        prev_value = curr_value;
        current = current ? current->next : NULL;
        i++;
    }

    // If no position found, return position of smallest element
    return (find_min_pos(stack_a));
}

int find_best_in_b_and_rotate(t_list **stack_b, t_list **stack_a, t_list **ops_list, int size_b)
{
	t_rotations best_move;
	t_rotations move;
	t_list *current_b;
	int size_a;
	int pos_b;

	current_b = *stack_b;
    size_a = ft_lstsize(*stack_a);
    pos_b = 0;
    best_move.total_moves = INT_MAX;

    while (current_b)
    {
        move.value = current_b->num;
        move.pos_b = pos_b;
        compute_rotations(pos_b, size_b, &move.rotations_b, &move.direction_b);
        move.pos_a = get_target_position_in_a(*stack_a, move.value);
        compute_rotations(move.pos_a, size_a, &move.rotations_a, &move.direction_a);
        if (move.direction_a == 'u' && move.direction_b == 'u')
            move.total_moves = MAX(move.rotations_a, move.rotations_b);
        else if (move.direction_a == 'd' && move.direction_b == 'd')
            move.total_moves = MAX(move.rotations_a, move.rotations_b);
        else
            move.total_moves = move.rotations_a + move.rotations_b;

        // Update best move
        if (move.total_moves < best_move.total_moves)
            best_move = move;

        pos_b++;
        current_b = current_b->next;
    }

    // Perform rotations based on best_move
    if (best_move.direction_a == 'u' && best_move.direction_b == 'u')
    {
        // Rotate both stacks up
        while (best_move.rotations_a > 0 && best_move.rotations_b > 0)
        {
            rotate(stack_a, 5, ops_list); // ra
			rotate(stack_b, 6, ops_list); // rb = rr
            best_move.rotations_a--;
            best_move.rotations_b--;
        }
        // Rotate remaining stack_a
        while (best_move.rotations_a-- > 0)
            rotate(stack_a, 5, ops_list); // ra
        // Rotate remaining stack_b
        while (best_move.rotations_b-- > 0)
            rotate(stack_b, 6, ops_list); // rb
    }
    else if (best_move.direction_a == 'd' && best_move.direction_b == 'd')
    {
        // Reverse rotate both stacks down
        while (best_move.rotations_a > 0 && best_move.rotations_b > 0)
        {
            reverse_rotate(stack_a, 8, ops_list); // rra
			reverse_rotate(stack_b, 9, ops_list); // rrb = rrr
            best_move.rotations_a--;
            best_move.rotations_b--;
        }
        // Reverse rotate remaining stack_a
        while (best_move.rotations_a-- > 0)
            reverse_rotate(stack_a, 8, ops_list); // rra
        // Reverse rotate remaining stack_b
        while (best_move.rotations_b-- > 0)
            reverse_rotate(stack_b, 9, ops_list); // rrb
    }
    else
    {
        // Rotate stack_a
        if (best_move.direction_a == 'u')
            while (best_move.rotations_a-- > 0)
                rotate(stack_a, 5, ops_list); // ra
        else
            while (best_move.rotations_a-- > 0)
                reverse_rotate(stack_a, 8, ops_list); // rra

        // Rotate stack_b
        if (best_move.direction_b == 'u')
            while (best_move.rotations_b-- > 0)
                rotate(stack_b, 6, ops_list); // rb
        else
            while (best_move.rotations_b-- > 0)
                reverse_rotate(stack_b, 9, ops_list); // rrb
    }

    return 0; // Return 0 on success
}
