#include "automata.h"

int	finish(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_image(v->mlx, (v->img).img);
	mlx_destroy_display(v->mlx);
	free(v->mlx);
	exit(0);
	return (0);
}

int	keyhook(int key, t_vars *v)
{
	if (65307 == key || 113 == key)
		return (finish(v));
	return (0);
}

int	mousehook(int button, int x, int y, t_vars *v)
{
	if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT)
		return (0);
	if (1 == button)
	{
		put_in_pixel(&v->img, x / SIZE, y / SIZE, SAND);
		mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, 0);
	}
	if (3 == button)
	{
		put_in_pixel(&v->img, x / SIZE, y / SIZE, FLOOR);
		mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, 0);
	}
	return (0);
}

int presshook(int x, int y, t_vars *v)
{
	mousehook(1, x, y, v);
	return (0);
}

int loophook(t_vars *v)
{
	int color;
	char	o;

	o = rand() % 2 ? 1 : -1;
	int x = WIDTH / SIZE - 1, y;
	while(x >= 0)
	{
	y = HEIGHT / SIZE;
	while (--y > 0)
	{
		color = get_color(v, x, y - 1);
		if (0 == color || FLOOR == color)
			continue ;
		if (0x0 == get_color(v, x, y))
			put_in_pixel(&v->img, x, y, color);
		else if (0x0 == get_color(v, x + o, y))
			put_in_pixel(&v->img, x + o, y, color);
		else if (0x0 == get_color(v, x - o, y))
			put_in_pixel(&v->img, x - o, y, color);
		else
			continue;
		put_in_pixel(&v->img, x, y - 1, 0x0);
		y--;
	}
	x--;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, 0);
	return (0);
}
