/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:49:22 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/11 18:45:00 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char *str)
{
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
	if (!str || !*str)
		return ;
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	push(t_list **lst1, t_list **lst2, char *str)
{
	t_list	*temp;

	if (!lst1 || !*lst1 || !lst2)
		return ;
	temp = (*lst1)->next;
	(*lst1)->next = *lst2;
	*lst2 = *lst1;
	*lst1 = temp;
	if (!str || !*str)
		return ;
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	rotate(t_list **lst, char *str)
{
	t_list	*last;
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last && last->next)
		last = last->next;
	temp = (*lst)->next;
	last->next = *lst;
	(*lst)->next = NULL;
	*lst = temp;
	if (!str || !*str)
		return ;
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_list **lst, char *str)
{
	t_list	*last;
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last = *lst;
	while (last && last->next)
	{
		if (last->next->next == NULL)
			temp = last;
		last = last->next;
	}
	last->next = *lst;
	*lst = last;
	temp->next = NULL;
	if (!str || !*str)
		return ;
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}
