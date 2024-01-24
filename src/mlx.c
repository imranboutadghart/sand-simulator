#include "automata.h"

int	init(t_vars *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		return (1);
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "automata");
	if (!v->win)
		return (mlx_destroy_display(v->mlx), 1);
	v->img.img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	if (!v->img.img)
		return (mlx_destroy_window(v->mlx, v->win),
				mlx_destroy_display(v->mlx),
				1);
	v->img.addr = mlx_get_data_addr(v->img.img,
			&v->img.bpp,
			&v->img.ll,
			&v->img.endian);
	return (0);
}
