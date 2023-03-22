/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 19:54:44 by akivioja      #+#    #+#                 */
/*   Updated: 2023/02/28 17:50:16 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
- combines res and buffer from the function "read_file" using strjoin
- frees buffer
- returns the joined strings
*/
char	*free_func(char *buffer, char *buf)
{
	char	*join;

	join = ft_strjoin(buffer, buf);
	if (join == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	free(buffer);
	return (join);
}

//used to set the new value to buffer variable
//Iterates through buffer until not true or \n to get the length
//Calloc is saved to line. The calloced amount is the len of file 
// -->(strlen on buffer) - len of first line (the iterated item)
//buffer is iterated again and all the items saved to line

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
	{
		free(buffer);
		free (line);
		return (NULL);
	}
		
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}


/*
This function does the following things:
- Checks that buffer has stuff
- Iterates through buffer to establish its length
- uses that len to calloc size saved to char line
- Loops through buffer until end or end of line 
- Saves each buffer character to line
- Checks if buffer had '\n' --> adds it to line if it did
- returns line
*/

/*get_linex that works
char	*get_linex(char *buffer)
{
	char		*line;
	size_t		count;

	line = get_line_helper(buffer);
	if (!line)
		return (NULL);
	count = 0;
	while (buffer[count] && buffer[count] != '\n')
	{
		line[count] = buffer[count];
		count++;
	}
	if (buffer[count] == '\n')
	{
		line[count++] = '\n';
		line[count] = '\0';
	}
	else
		line[count] = '\0';
	return (line);
}
*/

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

//This function reads content from specified
//fd to "res" in BUFFER_SIZE chun

char	*read_file(int fd, char	*res)
{
	char		*buffer;
	ssize_t		byte_count;

	if (!res)
		res = calloc (1, 1);
	buffer = calloc (BUFFER_SIZE + 1, sizeof(char));
	byte_count = 1;
	while (byte_count > 0)
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_count] = 0;
		res = free_func(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
