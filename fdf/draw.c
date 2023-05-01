/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 16:32:22 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/01 18:36:48 by akivioja      ########   odam.nl         */
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

void ft_slope(s_slope *ss)
{
	ss->dx = abs(ss->x1 - ss->x0);
	ss->dy = abs(ss->y1 - ss->y0);

	if (ss->dy > ss->dx)
	{
		ss->slope = 1;
		ss->swap = (ss->x0 > ss-> x1);
	}
	else
	{
		ss->slope = 0;
		ss->swap = 0;
	}
	// Step 2
	if (ss->x0 > ss->x1)
	{
		ss->x = ss->x0;
		ss->y = ss->y0;
		ss->swap = 0;
	}
	else
	{
		ss->x = ss->x1;
		ss->y = ss->y1;
		ss->swap = 1;

	}
}