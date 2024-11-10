/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:03 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/09 15:52:02 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	//
}

void	free_stack(t_list **lst)
{
	t_list	*current;

	if (!lst)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		free(*lst);
		*lst = current;
	}
	*lst = NULL;
}

int	ft_atoi_error(char *str, int *num)
{
	// checks thoroughly if each argument is valid
	// returns -1 in case or error
	// should handle INT_MAX and INT_MIN but return	-1 if larger/smaller than that
}

t_list	*ft_lstnew(int num)
{
	//
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	//
}

int	num_is_in_list(t_list *lst, int num)
{
	//
}
