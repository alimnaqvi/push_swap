/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_display_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:25 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/16 17:38:53 by anaqvi           ###   ########.fr       */
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

static int sort_three(t_list **stack, t_list **ops_list)
{
	t_list	*max_node;
	int status;

	status = 0;
	max_node = find_max_node(*stack);
	if (*stack == max_node)
		status = rotate(stack, 5, ops_list); // ra
	else if ((*stack)->next == max_node)
		status = reverse_rotate(stack, 8, ops_list); // rra
	if (status != -1 && (*stack)->num > (*stack)->next->num)
		status = swap(stack, 0, ops_list);  // sa
	return (status);
}

int	sort_and_display_ops(t_list **stack_a, t_list **stack_b, unsigned int list_size)
{
	unsigned int min_pos;
	unsigned int len_a;
	unsigned int len_b;
	t_list *ops_list;
	int status;

	ops_list = NULL;
	status = 0;
	len_a = list_size;
	len_b = 0;
	if (list_size == 2)
		status = swap(stack_a, 0, &ops_list);  // sa
	while (status != -1 && len_a-- > 3)
		status = push(stack_a, stack_b, 4, &ops_list); // pb
	if (status != -1 && ft_lstsize(*stack_a) == 3)
		status = sort_three(stack_a, &ops_list);
	while (status != -1 && *stack_b)
	{
		status = find_best_rotate(stack_b, stack_a, &ops_list, ft_lstsize(*stack_a));
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
	replace_double_op(&ops_list);
	remove_neutral_ops(&ops_list);
	display_ops(ops_list);
	free_stack(&ops_list);
	return (0);
}
