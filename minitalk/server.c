/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 13:52:10 by akivioja      #+#    #+#                 */
/*   Updated: 2023/04/21 17:54:05 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

// Two functions main & handler

void	handler_func(int signal)
{
	static int	bit;
	static int	shifts;

	if (signal == SIGUSR1)
		shifts |= (0x01 << bit);
	bit++;
	if(bit == 8)
	{
		ft_printf("%c", shifts);
		bit = 0;
		shifts = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	pid = getpid();
	//Server should print pid
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, handler_func);
		signal(SIGUSR2, handler_func);
		pause();
	}
	return (0);
}