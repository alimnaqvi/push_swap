/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:10:51 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/17 14:31:05 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int **arr, int arr_size)
{
	int				swapped;
	int				temp;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < arr_size - 1)
		{
			if ((*arr)[i] > (*arr)[i + 1])
			{
				temp = (*arr)[i];
				(*arr)[i] = (*arr)[i + 1];
				(*arr)[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

static int	*create_sorted_array(t_list *lst, int list_size)
{
	int				*arr;
	t_list			*current;
	int	i;

	arr = malloc(sizeof(int) * list_size);
	if (!arr)
		return (NULL);
	current = lst;
	i = 0;
	while (current)
	{
		arr[i++] = current->num;
		current = current->next;
	}
	sort_array(&arr, list_size);
	return (arr);
}

int	simplify_data(t_list *lst, int list_size)
{
	t_list			*current;
	int				*arr;
	int	index;

	arr = create_sorted_array(lst, list_size);
	if (!arr)
		return (-1);
	current = lst;
	while (current)
	{
		index = 0;
		while (index < list_size)
		{
			if (arr[index] == current->num)
				break ;
			index++;
		}
		current->num = index;
		current = current->next;
	}
	free(arr);
	return (0);
}
