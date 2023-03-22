/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:32:20 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/31 15:32:23 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nro;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nro = (unsigned int)(n * -1);
	}
	else
		nro = (unsigned int)n;
	if (nro >= 10)
		ft_putnbr_fd(nro / 10, fd);
	ft_putchar_fd((char)(nro % 10 + 48), fd);
}
