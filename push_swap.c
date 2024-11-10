/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:14:26 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/09 15:16:22 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *stack_a;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	if (parse_args_make_list(argc, argv, &stack_a) == -1)
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		exit(EXIT_SUCCESS);
	}
	if (sort_and_display_ops(&stack_a) == -1)
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	free_stack(&stack_a);
	exit(EXIT_SUCCESS);
}