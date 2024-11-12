/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:59:52 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/12 18:52:02 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;

int					parse_args_make_list(int argc, char **argv, t_list **lst);
int					parse_only_one_param(char *str, t_list **stack_a);

int					ft_atoi_error(char *str, int *num);

int					simplify_data(t_list *lst);
int					sort_and_display_ops(t_list **stack_a, t_list **stack_b);

void				swap(t_list **lst, char *str);
void				push(t_list **lst1, t_list **lst2, char *str);
void				rotate(t_list **lst, char *str);

char				**ft_split(char *s, char c);
void				reverse_rotate(t_list **lst, char *str);

t_list				*ft_lstnew(int num);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					num_is_in_list(t_list *lst, int num);
int					is_sorted(t_list *lst);
unsigned int		ft_lstsize(t_list *lst);

#endif