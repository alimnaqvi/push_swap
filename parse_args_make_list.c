/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_make_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:55:47 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/10 12:46:59 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args_make_list(int argc, char **argv, t_list **lst)
{
	// goes through arguments and adds them to stack a, returns -1 in case of error at any point (invalid argument, malloc failure, etc.)
	// does not free the so far malloced list, in case of error (handled by main)
	int i;
	int num;
	t_list	*current;

	i = 1;
	while (i < argc)
	{
		if (i = 1)
		{
			// handle case of all integers as one parameter
			// add first number to list because else if below
		}
		else if (ft_atoi_error(argv[i], &num) == -1)
			return (-1);
		else
		{
			if (num_is_in_list(*lst, num))
				return (-1);
			current = ft_lstnew(num);
			if (!current)
				return (-1);
			ft_lstadd_back(lst, current);
		}
		//
	}
	return (0);
}