/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:35:25 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/22 18:03:47 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_items(t_stack	**dlist)
{
	t_stack	*temp;

	temp = *dlist;
	if (temp->data < temp->next->data)
		return ;
	else if (temp->data > temp->next->data)
	{
		swap(temp, 0);
		return ;
	}
}

void	three_items(t_stack	**dlist)
{
	t_stack	*temp;
	int		top;
	int		middle;
	int		bottom;

	temp = *dlist;
	top = temp->data;
	middle = temp->next->data;
	bottom = temp->prev->data;
	if (top > middle && middle < bottom && bottom > top)
		swap(*dlist, 0);
	else if (top > middle && middle > bottom && bottom < top)
	{
		swap(*dlist, 0);
		reverse_rotate(dlist, 0);
	}
	else if (top > middle && middle < bottom && bottom < top)
		rotate(dlist, 0);
	else if (top < middle && middle > bottom && bottom > top)
	{
		swap(*dlist, 0);
		rotate(dlist, 0);
	}
	else if (top < middle && middle > bottom && bottom < top)
		reverse_rotate(dlist, 0);
}

void	five_items(t_stack **stackA, t_stack **stackB)
{
	t_stack	*temp;

	push(stackA, stackB, 1);
	push(stackA, stackB, 1);
	three_items(stackA);
	two_items(stackB);
	while ()
	temp = *stackA;
	push(stackB, stackA, 0);
	push(stackB, stackA, 0);
	temp = *stackA;

	if (temp->data > temp->next->data)
		swap(*stackA, 0);
	print_dlist(*stackA);
}

t_stack	*find_min(t_stack **dlist)
{
	t_stack	*temp;
	t_stack	*min_node;
	int		min;

	temp = *dlist;
	min_node = NULL;
	min = 2147483647;
	while (1)
	{
		if (temp->data < min && temp->index == -1)
		{
			min_node = temp;
			min = temp->data;
		}
		temp = temp->next;
		if (temp == *dlist)
			break ;
	}
	if (min_node == NULL)
		return (NULL);
	return (min_node);
}

int	assign_index(t_stack **dlist)
{
	t_stack	*min;
	int		index;

	min = *dlist;
	index = 0;
	while (1)
	{
		min = find_min(dlist);
		if (!min)
			break ;
		min->index = index;
		index++;
	}
	return (index);
}

int	size_of_index(int maxIndex)
{
	int		size_of_index;

	size_of_index = 0;
	while (maxIndex > 0)
	{
		maxIndex = maxIndex >> 1;
		size_of_index++;
	}
	return (size_of_index);
}

void	radix_sort(t_stack **stackA, t_stack	**stackB)
{
	t_stack	*temp;
	int		index;
	int		size;
	int		index_size;
	int		bit_position;

	index_size = size_of_index(assign_index(stackA));
	bit_position = 0;
	while (bit_position < index_size)
	{
		temp = *stackA;
		size = ft_dlstsize(*stackA);
		while (size > 0)
		{
			index = temp->index;
			temp = temp->next;
			if ((index & (1 << bit_position)) == 0 && size != 1)
				push(stackA, stackB, 0);
			else if ((index & (1 << bit_position)) == 0 && size == 1)
				break ;
			else
				rotate(stackA, 0);
			size--;
		}
		size = ft_dlstsize(*stackB);
		while (size-- > 0)
			push(stackB, stackA, 1);
		*stackB = NULL;
		bit_position++;
	}
}
