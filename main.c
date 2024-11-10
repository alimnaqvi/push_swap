/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:14:26 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/10 21:32:36 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_list **lst)
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

static void	ft_exit(int exit_status, t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (exit_status == 0)
		exit(EXIT_SUCCESS);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*
#include <stdio.h>
void check_print_list_exit(t_list *stack_a, t_list *stack_b)
{
	// delete this function
	t_list *current = stack_a;
	printf("Numbers saved in the stack a:\n");
	while (current)
	{
		printf("%i  ", current->num);
		current = current->next;
	}
	printf("\n");

	current = stack_b;
	printf("Numbers saved in the stack b:\n");
	while (current)
	{
		printf("%i  ", current->num);
		current = current->next;
	}
	printf("\n");

	ft_exit(0, &stack_a, &stack_b);
}
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (parse_args_make_list(argc, argv, &stack_a) == -1)
		ft_exit(1, &stack_a, &stack_b);
	if (is_sorted(stack_a))
		ft_exit(0, &stack_a, &stack_b);
	if (sort_and_display_ops(&stack_a, &stack_b) == -1) // change to void if always returns 0
		ft_exit(1, &stack_a, &stack_b);
	// check_print_list_exit(stack_a, stack_b); // delete
	ft_exit(0, &stack_a, &stack_b);
	return (0);
}
