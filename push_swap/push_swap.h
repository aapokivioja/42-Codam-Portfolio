/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:36:31 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/22 16:11:49 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

// llist functions
t_stack			*ft_dlstnew(int content);
t_stack			*create_dlist(char **argv, int size);
t_stack			*ft_dlstadd_front(t_stack *dlst, t_stack *new);
t_stack			*ft_dremove_node(t_stack *removed_node);
int				ft_dlstsize(t_stack *dlst);
t_stack			*ft_dlstlast(t_stack *dlst);
void			ft_dlstclear(t_stack **dlst);

int				push_swap(char **argv, int argc);
t_stack			*create_dlist(char **argv, int size);
void			print_dlist(t_stack *head);

// operations
void			swap(t_stack *head, int SaSb);
void			push(t_stack **pushedNode, t_stack **receivingStack, int PaPb);
void			rotate(t_stack **dlist, int RaRb);
void			reverse_rotate(t_stack **dlist, int RraRrb);
void			swap_both(t_stack *stackA, t_stack *stackB);
void			rotate_both(t_stack **stackA, t_stack **stackB);
void			reverse_rotate_both(t_stack **stackA, t_stack **stackB);

// algo
void			two_items(t_stack **dlist);
void			three_items(t_stack **dlist);
void			five_items(t_stack **stackA, t_stack **stackB);
void			radix_sort(t_stack **stackA, t_stack **stackB);
t_stack			*find_min(t_stack **dlist);
int				assign_index(t_stack **dlist);

// Errors
int				error_check(char **argv, int argc);
int				is_sorted(char **argv, int argc);

#endif
