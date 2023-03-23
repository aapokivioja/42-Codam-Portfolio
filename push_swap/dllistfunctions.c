/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dllistfunctions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:35:32 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/22 14:56:00 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//works but only takes int
t_stack	*ft_dlstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node -> data = content;
	new_node -> index = -1;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}

// works
// Returns the head of the stack
// In doubly circular linked lists adding back and fron
// are the same thing
// This function creates a problem when the pushed node is the last node
// Currently handled in the radixSort by setting stackB = NULL
// Might be an issue elsewhere as well.
t_stack	*ft_dlstadd_front(t_stack *dlst, t_stack *new)
{
	t_stack	*current_head;
	t_stack	*current_tail;

	current_head = dlst;
	if (!current_head)
	{
		new -> next = new;
		new -> prev = new;
		return (new);
	}
	current_tail = current_head -> prev;
	new -> next = current_head;
	new -> prev = current_tail;
	current_head -> prev = new;
	current_tail -> next = new;
	return (new);
}

//Returns new head of stack (next)
t_stack	*ft_dremove_node(t_stack	*removed_node)
{
	t_stack	*rm_node_next;
	t_stack	*rm_node_prev;

	rm_node_next = removed_node->next;
	rm_node_prev = removed_node->prev;
	rm_node_next->prev = rm_node_prev;
	rm_node_prev->next = rm_node_next;
	return (rm_node_next);
}

// works
// Returns num of items -> starts from 1
int	ft_dlstsize(t_stack *dlst)
{
	int		count;
	t_stack	*temp;

	if (dlst == NULL)
		return (0);
	count = 1;
	temp = dlst;
	while (temp->next != dlst)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

// works
t_stack	*ft_dlstlast(t_stack *dlst)
{
	t_stack	*temp;

	temp = dlst;
	while (temp->next != dlst)
		temp = temp->next;
	return (temp);
}

//Idk if this works
// I think it does
void	ft_dlstclear(t_stack **dlst)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *dlst;
	while (temp->next != *dlst)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
/*
void ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack *ft_lstmap(t_stack *lst, void *(*f)(void *),
void (*del)(void *));

*/
