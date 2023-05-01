/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:36:44 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/01 16:16:40 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int col, row = 0;
	r_fdf	*data;

	(void)argc;
	data = (r_fdf*)malloc(sizeof(r_fdf));
	parse(argv[1], data);
	while(row < data->height)
	{
		col = 0;
		while(col < data->width)
		{
			printf("%3d", data->int_matrix[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	return (0);
}