/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 19:54:54 by akivioja      #+#    #+#                 */
/*   Updated: 2023/02/28 17:45:00 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_helper(char	*buffer)
{
	ssize_t	count;
	char	*line;

	count = 0;
	if (!buffer[count])
		return (NULL);
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (buffer[count] == '\n')
		count++;
	line = (char *)malloc(sizeof(char) * count + 1);
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	size_t	count;

	if (!s1 || !s2)
		return (NULL);
	j_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!j_str)
		return (NULL);
	count = 0;
	while (*s1)
		j_str[count++] = *s1++;
	while (*s2)
		j_str[count++] = *s2++;
	j_str[count] = '\0';
	return (j_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}


// copied shit

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	ft_bzero(res, elementSize * elementCount);
	return (res);
}