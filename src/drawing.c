#include "automata.h"

void	put_in_pixel(t_data *img, int x, int y, int c)
{
	char	*data;
	int i = 0, j = 0;

	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			data = img->addr + y * img->ll * SIZE + x * (img->bpp / 8) * SIZE + img->ll * i + (img->bpp / 8) * j++;
			*(unsigned int *) data = c;
		}
	i++;
	}
}

void	flour(t_vars *v)
{
	int	i;

	i = 0;
	while (i <= WIDTH / SIZE)
	{
		put_in_pixel(&v->img, i, HEIGHT / SIZE - HEIGHT / 7 / SIZE, FLOOR);
		i++;
	}
}
