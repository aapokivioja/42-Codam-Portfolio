/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:35:44 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/22 16:17:33 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

t_stack	*create_dlist(char **argv, int size)
{
	t_stack	*head;
	t_stack	*tail;

	head = NULL;
	tail = NULL;
	size--;
	if (size > 0)
	{
		head = ft_dlstnew(ft_atoi(argv[1]));
		tail = head;
		argv++;
		while (*argv && --size)
		{
			tail->next = ft_dlstnew(ft_atoi(*++argv));
			tail->next->prev = tail;
			tail = tail->next;
		}
		tail->next = head;
		head->prev = tail;
	}
	return (head);
}

void	print_dlist(t_stack *head)
{
	t_stack	*temp;
	int		size;

	temp = head;
	if (head == NULL)
	{
		ft_printf("List is empty");
		return ;
	}
	size = ft_dlstsize(head);
	while (size > 0)
	{
		ft_printf("%s%d%s%d\n", "Data: ", temp->data, " Index: ", temp->index);
		size--;
		temp = temp->next;
	}
}

int	push_swap(char **argv, int argc)
{
	t_stack	*ahead;
	t_stack	*bhead;

	if (error_check(argv, argc) == -1)
		return (write(1, "Error\n", 6), 0);
	if (argc <= 2 || is_sorted(argv, argc) == -1)
		return (0);
	ahead = create_dlist(argv, argc);
	bhead = NULL;
	if (argc == 3)
		two_items(&ahead);
	else if (argc == 4)
		three_items(&ahead);
	else if (argc == 6)
		five_items(&ahead, &bhead);
	else
		radix_sort(&ahead, &bhead);
	return (0);
}
