/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:36:44 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/13 16:55:39 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, r_fdf *data)
{
	ft_printf("%d\n", key);
	
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 69)
		data->zoom += 3;
	if (key == 78)
		data->zoom -= 3;
	if (key == 86)
		data->angle += 0.05;
	if (key == 88)
		data->angle -= 0.05;
	mlx_clear_window(data -> mlx_ptr, data -> win_ptr);
	draw(data);
	return (0);
}



int main(int argc, char **argv)
{
	r_fdf	*data;

	(void)argc;
	data = (r_fdf*)malloc(sizeof(r_fdf));
	parse(argv[1], data);


	//All these go into init
	data -> shift_x = 300;
	data -> shift_y = 300;
	data -> angle = 0.523599;
	data -> mlx_ptr = mlx_init();
	data -> win_ptr = mlx_new_window(data -> mlx_ptr, 1000, 1000, "FDF");

	data -> zoom = 20;
	draw(data);
	// This hook thing is something for the bonus idfk
	mlx_key_hook(data -> win_ptr, deal_key, data);
	mlx_loop(data -> mlx_ptr);
	
	return (0);
}