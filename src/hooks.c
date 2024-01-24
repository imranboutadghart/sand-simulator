#include "automata.h"

int	finish(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_image(v->mlx, (v->img).img);
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

int presshook1(int x, int y, t_vars *v)
{
	mousehook(1, x, y, v);
	return (0);
}

int presshook2(int x, int y, t_vars *v)
{
	mousehook(3, x, y, v);
	return (0);
}

int releasehook(int button, t_vars *v)
{
	(void) button;
	(void) v;
	printf("key released\n");
	return (0);
}

int loophook(t_vars *v)
{
	static struct timeval old;
	struct timeval new;
	int color;
	if (!old.tv_usec)
		gettimeofday(&old, NULL);
	gettimeofday(&new, NULL);
	if (0 && ((new.tv_sec - old.tv_sec) * 1000000 + (new.tv_usec - old.tv_usec )) * 120 < 1000000)
		return (0);
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
		else if (0x0 == get_color(v, x + 1, y))
			put_in_pixel(&v->img, x + 1, y, color);
		else if (0x0 == get_color(v, x - 1, y))
			put_in_pixel(&v->img, x - 1, y, color);
		else
			continue;
		put_in_pixel(&v->img, x, y - 1, 0x0);
		y--;
	}
	x--;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, 0);
	gettimeofday(&old, NULL);
	return (0);
}
