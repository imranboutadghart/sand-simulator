#include "automata.h"

int main()
{
	t_vars	v;

	if (init(&v))
		return (1);
	flour(&v);
	mlx_put_image_to_window(v.mlx, v.win, v.img.img, 0, 0);
	mlx_hook(v.win, 17, 0, finish, &v); //the exit button
	mlx_hook(v.win, 6,(1 << 8), presshook, &v); //mouse moving while click
	mlx_hook(v.win, 2, (1L << 0), keyhook, &v); //keydown
	mlx_mouse_hook(v.win, mousehook, &v);
	mlx_loop_hook(v.mlx, loophook, &v);
	mlx_loop(v.mlx);
	return (0);
}
