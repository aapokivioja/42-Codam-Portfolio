/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:31:35 by akivioja      #+#    #+#                 */
/*   Updated: 2023/04/29 19:52:47 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char	*filename)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(filename, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	count_words(char *line)
{
	int	word_count;
	int	index;

	word_count = 0;
	index = 0;

	while (line[index])
	{
		while (line[index] == ' ' && line[index] != '\0')
			index++;
		if (line[index])
			word_count++;
		while (line[index] != ' ' && line[index] != '\0')
			index++;
	}
	return (word_count);
}

int	get_width(char *filename)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	width = count_words(line);
	/*This while loops fixes a weird problem where
	gnl remembers it alredy read the first line
	-> causes an issue later on when The whole file needs to be read again
	-> Starts from second line bcs 1 is already read
	-> Now we read all the lines again
	*/
	while (line)
		line = get_next_line(fd);
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *row, char *line)
{
	char	**nums;
	int		index;

	nums = ft_split(line, ' ');
	index = 0;
	while (nums[index])
	{
		row[index] = ft_atoi(nums[index]);
		free(nums[index]);
		index++;
	}
	free(nums);

}

void parse(char	*filename, r_fdf *data)
{
	int		index;
	int		fd;
	char	*line;

	data -> height = get_height(filename);
	data -> width = get_width(filename);

	//malloc room for all columns
	data->int_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	index = 0;
	//malloc room for all rows
	while (index <= data->height)
		data->int_matrix[index++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	index = 0;
	while (line)
	{
		fill_matrix(data->int_matrix[index], line);
		line = get_next_line(fd);
		index++;
	}
	free(line);
	close(fd);
	data->int_matrix[index] = NULL;
}