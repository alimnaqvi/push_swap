/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewest_moves_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:58:31 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/15 16:49:57 by anaqvi           ###   ########.fr       */
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

int get_target_position_in_b(t_list *stack_b, int value)
{
    int pos = 0;
    int pos_max = 0;
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    int size = ft_lstsize(stack_b);
    t_list *current = stack_b;

    if (!stack_b)
        return 0;

    // Find the position where 'value' fits in 'stack_b'
    for (int i = 0; current; current = current->next, i++)
    {
        int curr_value = current->num;

        // Update max and min
        if (curr_value > max_value)
        {
            max_value = curr_value;
            pos_max = i;
        }
        if (curr_value < min_value)
            min_value = curr_value;

        // If value should be placed between current and next
        if (current->next)
        {
            int next_value = current->next->num;
            if (value < curr_value && value > next_value)
                return i + 1;
        }
        else
        {
            // Check the end to start wrap-around
            if (value < curr_value && value > stack_b->num)
                return 0;
        }
    }

    // If value is greater than max or less than min, insert after max_value
    if (value > max_value || value < min_value)
        return pos_max + 1;

    // Should not reach here
    return 0;
}

int get_target_position_in_a(t_list *stack_a, int value)
{
    int pos = 0;
    int pos_min = 0;
    int min_moves = INT_MAX;
    t_list *current = stack_a;

    if (!stack_a)
        return 0;

    int size = ft_lstsize(stack_a);
    int prev_value = stack_a->num;
    current = stack_a->next;

    for (int i = 1; i <= size; i++)
    {
        int curr_value = current ? current->num : stack_a->num;
        if ((value > prev_value && value < curr_value) ||
            (prev_value > curr_value && (value > prev_value || value < curr_value)))
        {
            // Found the right position
            return i % size;
        }
        prev_value = curr_value;
        current = current ? current->next : NULL;
    }

    // If no position found, return position of smallest element
    current = stack_a;
    int min_value = INT_MAX;
    for (int i = 0; current; i++, current = current->next)
    {
        if (current->num < min_value)
        {
            min_value = current->num;
            pos_min = i;
        }
    }
    return pos_min;
}

int find_best_in_a_and_rotate(t_list **stack_a, t_list **stack_b, t_list **ops_list, unsigned int list_size)
{
    t_list *current_a = *stack_a;
    int size_a = ft_lstsize(*stack_a);
    int size_b = ft_lstsize(*stack_b);
    int pos_a = 0;
    t_rotations best_move;
    best_move.total_moves = INT_MAX;

    while (current_a)
    {
        t_rotations move;
        move.value = current_a->num;
        move.pos_a = pos_a;
        compute_rotations(pos_a, size_a, &move.rotations_a, &move.direction_a);

        // Get target position in stack_b
        move.pos_b = get_target_position_in_b(*stack_b, move.value);
        compute_rotations(move.pos_b, size_b, &move.rotations_b, &move.direction_b);

        // Calculate total moves for different cases
        // Case 1: Both directions are up
        if (move.direction_a == 'u' && move.direction_b == 'u')
            move.total_moves = MAX(move.rotations_a, move.rotations_b);
        // Case 2: Both directions are down
        else if (move.direction_a == 'd' && move.direction_b == 'd')
            move.total_moves = MAX(move.rotations_a, move.rotations_b);
        // Case 3 & 4: Different directions
        else
            move.total_moves = move.rotations_a + move.rotations_b;

        // Update best move
        if (move.total_moves < best_move.total_moves)
            best_move = move;

        pos_a++;
        current_a = current_a->next;
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

int find_best_in_b_and_rotate(t_list **stack_b, t_list **stack_a, t_list **ops_list, unsigned int list_size)
{
    t_list *current_b = *stack_b;
    int size_b = ft_lstsize(*stack_b);
    int size_a = ft_lstsize(*stack_a);
    int pos_b = 0;
    t_rotations best_move;
    best_move.total_moves = INT_MAX;

    while (current_b)
    {
        t_rotations move;
        move.value = current_b->num;
        move.pos_b = pos_b;
        compute_rotations(pos_b, size_b, &move.rotations_b, &move.direction_b);

        // Get target position in stack_a
        move.pos_a = get_target_position_in_a(*stack_a, move.value);
        compute_rotations(move.pos_a, size_a, &move.rotations_a, &move.direction_a);

        // Calculate total moves for different cases
        // Case 1: Both directions are up
        if (move.direction_a == 'u' && move.direction_b == 'u')
            move.total_moves = MAX(move.rotations_a, move.rotations_b);
        // Case 2: Both directions are down
        else if (move.direction_a == 'd' && move.direction_b == 'd')
            move.total_moves = MAX(move.rotations_a, move.rotations_b);
        // Case 3 & 4: Different directions
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
