/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:35:36 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/22 15:09:58 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Works for both stacks
// 0 - sa, 1-sb, 2-ss
void	swap(t_stack *head, int SaSb)
{
	int		tmp_data;
	t_stack	*tmp_node;

	if (head->next == NULL)
		return ;
	tmp_node = head->next;
	tmp_data = head->data;
	head->data = tmp_node->data;
	tmp_node->data = tmp_data;
	if (SaSb == 0)
		write (1, "sa\n", 3);
	else if (SaSb == 1)
		write (1, "sb\n", 3);
	else if (SaSb == 2)
		write (1, "ss\n", 3);
	else
		return ;
}

//Works
void	swap_both(t_stack *stackA, t_stack *stackB)
{
	swap(stackA, 2);
	swap(stackB, 3);
}

//works for both stacks
// 0 - pa, 1-pb
void	push(t_stack **pushedNode, t_stack **receivingStack, int PaPb)
{	
	t_stack	*temp;

	if (*pushedNode == NULL)
		return ;
	temp = *pushedNode;
	*pushedNode = ft_dremove_node(*pushedNode);
	*receivingStack = ft_dlstadd_front(*receivingStack, temp);
	if (PaPb == 0)
		write (1, "pb\n", 3);
	else
		write (1, "pa\n", 3);
}

// Works
void	rotate(t_stack	**dlist, int RaRb)
{
	t_stack	*temp;

	temp = *dlist;
	*dlist = temp->next;
	if (RaRb == 0)
		write (1, "ra\n", 3);
	else if (RaRb == 1)
		write (1, "rb\n", 3);
	else if (RaRb == 2)
		write (1, "rr\n", 3);
	else
		return ;
}

void	rotate_both(t_stack	**stackA, t_stack	**stackB)
{
	rotate(stackA, 2);
	rotate(stackB, 3);
}

void	reverse_rotate(t_stack	**dlist, int RraRrb)
{
	t_stack	*temp;

	temp = *dlist;
	*dlist = temp -> prev;
	if (RraRrb == 0)
		write (1, "rra\n", 4);
	else if (RraRrb == 1)
		write (1, "rrb\n", 4);
	else if (RraRrb == 2)
		write (1, "rrr\n", 4);
	else
		return ;
}

void	reverse_rotate_both(t_stack	**stackA, t_stack	**stackB)
{
	reverse_rotate(stackA, 2);
	reverse_rotate(stackB, 3);
}
