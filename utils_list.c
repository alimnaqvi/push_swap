/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:03 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/12 18:23:22 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!(new_node))
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	last = *lst;
	while (last && last->next)
		last = last->next;
	if (!last)
		*lst = new;
	else
		last->next = new;
}

int	num_is_in_list(t_list *lst, int num)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		if (current->num == num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current->next == NULL)
		return (1);
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;
	t_list			*current;

	count = 0;
	if (!lst)
		return (count);
	current = lst;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
