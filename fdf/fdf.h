/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:55 by akivioja      #+#    #+#                 */
/*   Updated: 2023/04/29 17:21:38 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#define HEIGHT		1080
#define WIDTH		1920
#define MENU_WIDTH	250

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

	void	*mlx_ptr;
	void	*win_ptr;

}	r_fdf;

void parse(char	*filename, r_fdf *data);



#endif
