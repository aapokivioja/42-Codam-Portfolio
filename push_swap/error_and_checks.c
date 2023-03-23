/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 14:48:06 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/22 15:53:33 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	has_duplicates(char **argv, int argc)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			k = 0;
			while (argv[i][k] != '\0' && argv[j][k] != '\0')
			{
				if (argv[i][k] != argv[j][k])
					break ;
				k++;
			}
			if (argv[i][k] == '\0' && argv[j][k] == '\0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	non_numeric(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(char **argv, int argc)
{
	argc--;
	while (argc > 1)
	{
		if (ft_atoi(argv[argc - 1]) > ft_atoi(argv[argc]))
			return (0);
		argc--;
	}
	return (-1);
}

int	error_check(char **argv, int argc)
{
	int	count;

	count = 1;
	if (has_duplicates(argv, argc) == -1)
		return (-1);
	if (non_numeric(argv, argc) == -1)
		return (-1);
	return (0);
}
