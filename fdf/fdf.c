/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:46 by akivioja      #+#    #+#                 */
/*   Updated: 2023/04/29 17:08:34 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"

/*
static t_fdf	*ft_init()
{
	t_fdf	*env;

	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ft_printf("malloc error");
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_printf("init error");
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Moi");
	if (!env->win)
		ft_printf("Win error");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_printf("Img error");
	env->data_ptr = mlx_get_data_addr(env->img, &env->bits_per_pixel, &env->line_size, &env->endian);
	

	return (env);
}

int ft_pixel(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}


int main(int argc, char **argv)
{
	int		fd;
	int		row;
	int		col;
	char	*line;
	//t_map	*map;
	t_point	*point;

	point = NULL;
	argc = 0;
	int x = 0;
	int y = 0;
	t_fdf	*env;
	env = ft_init();
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, ft_pixel(0, 191, 255, 255));
			y++;
		}
		x++;
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	row = 0;
	while (line)
	{
		col = 0;
		while (line[col])
		{
			point->x = col;
			point->y = row;
			point->z = line[col];
			col++;
		}
		line = get_next_line(fd);
		row++;
	}
	
	mlx_loop(env->mlx);
	return (0);
}
*/