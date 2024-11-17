/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:16:10 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/17 14:34:01 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_ops(t_list *ops_list)
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

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	find_min_pos(t_list *stack)
{
	int	i;
	int	min;
	int	min_pos;

	i = 0;
	min = INT_MAX;
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

t_list	*find_max_node(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (max->num < stack->num)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
