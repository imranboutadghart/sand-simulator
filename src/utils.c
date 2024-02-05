#include "automata.h"

int	random_color()
{
	static int color = 0;

	color += ((rand() % 0x0a) << 16) + ((rand() % 0x0b) << 8) + (rand() % 0x0c);
	if (!color || FLOOR == color)
		color += ((rand() % 0x0a) << 16) + ((rand() % 0x0b) << 8) + (rand() % 0x0c);
	return (color);
}

int	get_color(t_vars *v, int x, int y)
{
	char *data;
	t_data *img = &v->img;
	data = img->addr + y * img->ll * SIZE + x * (img->bpp / 8) * SIZE;
	return (*(unsigned int *)data);
}
