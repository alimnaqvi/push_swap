/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:59:52 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/17 14:55:45 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX(x, y) ((x > y) * (x) + (x <= y) * (y))

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;

typedef struct s_rotations
{
	int				rotations_a;
	int				rotations_b;
	int				total_moves;
	char			direction_a;
	char			direction_b;
	int				pos_a;
	int				pos_b;
	int				value;
}					t_rotations;

int					parse_args_make_list(int argc, char **argv, t_list **lst);
int					parse_only_one_param(char *str, t_list **stack_a);
void				free_stack(t_list **lst);

int					ft_atoi_error(char *str, int *num);

int					simplify_data(t_list *lst, int list_size);
int					sort_and_display_ops(t_list **stack_a, t_list **stack_b,
						int size_a);

t_rotations			find_best_move(t_list *stack_a, t_list *stack_b, int size_a,
						int size_b);

int					perform_best_move_rotations(t_list **stack_a,
						t_list **stack_b, t_list **ops_list,
						t_rotations best_move);

int					swap(t_list **stack, int op, t_list **ops_list);
int					push(t_list **stack_1, t_list **stack_2, int op,
						t_list **ops_list);
int					rotate(t_list **stack, int op, t_list **ops_list);
int					reverse_rotate(t_list **stack, int op, t_list **ops_list);

void				remove_neutral_ops(t_list **ops_list);
void				replace_double_op(t_list **ops_list);

void				display_ops(t_list *ops_list);
size_t				ft_strlen(char *s);
int					find_min_pos(t_list *stack);
t_list				*find_max_node(t_list *stack);

char				**ft_split(char *s, char c);

t_list				*ft_lstnew(int num);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					num_is_in_list(t_list *lst, int num);
int					is_sorted(t_list *lst);
int					ft_lstsize(t_list *lst);

#endif