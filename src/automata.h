/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:20:56 by iboutadg          #+#    #+#             */
/*   Updated: 2024/01/24 15:12:35 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000
# define SAND 0x00ffff00//random_color()
//# define SAND random_color()
# define FLOOR 0x00654321
# define SIZE	3

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_data;

typedef struct s_vars
{
	t_data	img;
	void	*mlx;
	void	*win;
	int	mousex;
	int	mousey;
	char	mousepressed;
}			t_vars;

//drawing functions
void		flour(t_vars *v);
//hooks funstions
int	finish(t_vars *v);
int	keyhook(int keycode, t_vars *v);
int	mousehook(int button, int x, int y, t_vars *v);
int	presshook(int x, int y, t_vars *v);
int	loophook(t_vars *v);
//mlx functions
int	init(t_vars *v);
void	put_in_pixel(t_data *img, int x, int y, int c);
//utils
int	get_color(t_vars *v, int x, int y);
int	random_color();

#endif //FRACTOL_H
