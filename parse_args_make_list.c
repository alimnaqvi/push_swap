/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_make_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:55:47 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/10 16:47:32 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args_make_list(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		num;
	t_list	*current;

	/* goes through arguments and adds them to stack a, returns
		-1 in case of error at any point (invalid argument, malloc failure,
		etc.) does not free the so far malloced list,
		in case of error (handled by main) */
	i = 1;
	while (i < argc)
	{
		if (argc == 2 && i == 1)
			return (parse_only_one_param(argv[i], stack_a));
		if (ft_atoi_error(argv[i], &num) == -1)
			return (-1);
		else
		{
			if (num_is_in_list(*stack_a, num))
				return (-1);
			current = ft_lstnew(num);
			if (!current)
				return (-1);
			ft_lstadd_back(stack_a, current);
		}
		i++;
	}
	return (0);
}

int	parse_only_one_param(char *str, t_list **stack_a)
{
	int		i;
	int		num;
	char	**splits;
	t_list	*current;

	splits = ft_split(str, ' ');
	if (!splits)
		return (-1);
	i = 0;
	while (splits[i])
	{
		if (ft_atoi_error(splits[i++], &num) == -1)
			return (free_splits(splits), -1);
		else
		{
			if (num_is_in_list(*stack_a, num))
				return (free_splits(splits), -1);
			current = ft_lstnew(num);
			if (!current)
				return (free_splits(splits), -1);
			ft_lstadd_back(stack_a, current);
		}
	}
	free_splits(splits);
	return (0);
}