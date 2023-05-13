/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:55 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/13 16:44:13 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#define HEIGHT		1080
#define WIDTH		1920
#define MENU_WIDTH	250

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"

typedef struct s_FdF
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_ptr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;

}	t_fdf;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct	s_map
{
	t_point		**position;
	int			x;
	int			y;
	int			z;
}	t_map;

// Motherfucker

typedef struct 
{
	int	width;
	int	height;
	int	**int_matrix;
	int	zoom;
	int	color;
	int	shift_x;
	int	shift_y;
	double	angle;

	void	*mlx_ptr;
	void	*win_ptr;
}	r_fdf;

typedef struct
{
	int x;
	int y;
	int x0;
	int y0;
	int x1;
	int y1;
	int dx;
	int dy;
	int	slope;
	int swap;
}	s_slope;

void parse(char	*filename, r_fdf *data);
void bresenham(float x, float y, float x1, float y1, r_fdf *data);
void	draw(r_fdf *data);


#endif
