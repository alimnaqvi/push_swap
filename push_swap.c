/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:49:22 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/13 11:19:11 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack, int op, t_list **ops_list)
{
	t_list	*temp;
	t_list	*op_node;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	op_node = ft_lstnew(op);
	if (!op_node)
		return (-1);
	ft_lstadd_back(ops_list, op_node);
	return (0);
}

int	push(t_list **stack_1, t_list **stack_2, int op, t_list **ops_list)
{
	t_list	*temp;
	t_list	*op_node;

	if (!stack_1 || !*stack_1 || !stack_2)
		return (0);
	temp = (*stack_1)->next;
	(*stack_1)->next = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = temp;
	op_node = ft_lstnew(op);
	if (!op_node)
		return (-1);
	ft_lstadd_back(ops_list, op_node);
	return (0);
}

int	rotate(t_list **stack, int op, t_list **ops_list)
{
	t_list	*last;
	t_list	*temp;
	t_list	*op_node;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = *stack;
	while (last && last->next)
		last = last->next;
	temp = (*stack)->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
	op_node = ft_lstnew(op);
	if (!op_node)
		return (-1);
	ft_lstadd_back(ops_list, op_node);
	return (0);
}

int	reverse_rotate(t_list **stack, int op, t_list **ops_list)
{
	t_list	*last;
	t_list	*temp;
	t_list	*op_node;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = *stack;
	while (last && last->next)
	{
		if (last->next->next == NULL)
			temp = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	temp->next = NULL;
	op_node = ft_lstnew(op);
	if (!op_node)
		return (-1);
	ft_lstadd_back(ops_list, op_node);
	return (0);
}
