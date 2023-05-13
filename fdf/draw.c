/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 16:32:22 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/13 16:46:07 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
In this file lets create two
separate algorithms
(1) - Bresenham
(2) - Xiaolin Wu
*/

/* Func 1:
- Calculate slope and determine if need for swap

*/

float 	mod(float i)
{
	if (i < 0)
		return -i;
	else
		return i;
}

int	MAX(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	isometric (float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;

}

void	bresenham(float x, float y, float x1, float y1, r_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data -> int_matrix[(int)y][(int)x];
	z1 = data -> int_matrix[(int)y1][(int)x1];

	// -- Zoom -- 

	x *= data -> zoom;
	y *= data -> zoom;
	x1 *= data -> zoom;
	y1 *= data -> zoom;

	//  -- Color --
	if (z || z1)
		data -> color = 0xffc0cb;
	else
		data -> color = 0xffffff;

	// -- 3d --

	isometric(&x, &y, z, data->angle);
	isometric(&x1, &y1, z1, data->angle);

	// -- Key shifts --

	/* Fake 
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;
	*/
	
	// Real
	x += data -> shift_x;
	y += data -> shift_y;
	x1 += data -> shift_x;
	y1 += data -> shift_y;
	
	
	// Figure out how many steps to the left and down
	//from a point

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data -> mlx_ptr, data -> win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(r_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data -> height)
	{
		x = 0;
		while (x < data -> width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data -> height -1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}