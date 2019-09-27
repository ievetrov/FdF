
#include "../includes/fdf.h"

void	ft_init(t_show *p)
{
	p->deep = 0;
	p->tight = 0;
	p->tight2 = 0;
	p->zoom = WIDTH;
	p->persp = 1;
	p->r = 255;
	p->g = 255;
	p->b = 255;
	p->color = 0;
}

int		ft_build_mlx(t_show *p)
{
	ft_init(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fdf");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	mlx_hook(p->win, 2, 2, ft_key_main, p);
	mlx_mouse_hook(p->win, ft_mouse_hook, p);
	mlx_loop(p->mlx);
	return (0);
}
