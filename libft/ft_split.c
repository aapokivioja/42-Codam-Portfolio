/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 17:22:20 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/27 14:49:11 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**getarr(char const *s, char c)
{
	int		count;
	int		since_c;
	int		num_of_strs;
	char	**ptr_to_arr;

	count = 0;
	since_c = 0;
	num_of_strs = 0;
	while (s[count])
	{
		if (s[count] == c && s[count + 1] != c && count != 0)
		{
			num_of_strs++;
			since_c = -1;
		}
		since_c++;
		count++;
	}
	if (since_c > 0)
		num_of_strs++;
	ptr_to_arr = (char **) malloc((num_of_strs + 1) * sizeof(char *));
	return (ptr_to_arr);
}

static void	freearr(char **ptr, unsigned int str_num)
{
	while (str_num)
	{
		free(ptr[str_num]);
		str_num--;
	}
	free(ptr);
}

static char	**ptr_returner(char const *s, char c, char **p, unsigned int k)
{
	unsigned int	tmp_count;
	unsigned int	str_num;

	str_num = 0;
	while (s[k])
	{
		tmp_count = k;
		if (s[k] != c)
		{
			while (s[tmp_count] != c && s[tmp_count])
				tmp_count++;
			p[str_num] = ft_substr(s, k, tmp_count - k);
			if (!p[str_num])
			{
				freearr(p, str_num - 1);
				return (NULL);
			}
			k = tmp_count + (str_num++ *0);
		}
		if (!s[k])
			break ;
		k++;
	}
	p[str_num] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr;

	if (!s)
		return (NULL);
	ptr = getarr(s, c);
	if (!ptr)
		return (NULL);
	ptr_returner(s, c, ptr, 0);
	return (ptr);
}
