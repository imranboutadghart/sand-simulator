#include "automata.h"

int	random_color()
{
	int color;

	color = 0;
	while (!color || FLOOR == color)
		color = rand() % 0xffffff;
	return (color);
}

int	get_color(t_vars *v, int x, int y)
{
	char *data;
	t_data *img = &v->img;
	data = img->addr + y * img->ll * SIZE + x * (img->bpp / 8) * SIZE;
	return (*(unsigned int *)data);
}
