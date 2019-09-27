
#include "../includes/fdf.h"

int					ft_key_main(int keycode, t_show *sh)
{
	int				i;
	int				j;

	i = 1;
	if (keycode == ESCAPE)
		exit(1);
	if (keycode == UP)
		sh->tight -= 30;
	if (keycode == DOWN)
		sh->tight += 30;
	if (keycode == RIGHT)
		sh->tight2 += 30;
	if (keycode == LEFT)
		sh->tight2 -= 30;
	if (keycode == 29)
		ft_reset(sh);
	return (ft_key_zoomcolor(keycode, sh));
}

int					ft_key_zoomcolor(int keycode, t_show *sh)
{
	if (keycode == DEZOOM)
	{
		sh->zoom -= 50;
		sh->tight2 += 25;
		sh->tight += 25;
	}
	if (keycode == ZOOM)
	{
		sh->zoom += 50;
		sh->tight2 -= 25;
		sh->tight -= 25;
	}
	if (keycode == 11)
		sh->color = 1;
	if (keycode == 5)
		sh->color = 2;
	if (keycode == 15)
		sh->color = 3;
	return (ft_key_rgb(keycode, sh));
}

int					ft_key_rgb(int keycode, t_show *sh)
{
	if (keycode == 14)
		sh->r = ((sh->r -= 10) < 0) ? 0 : sh->r - 10;
	if (keycode == 3)
		sh->g = ((sh->g -= 10) < 0) ? 0 : sh->g - 10;
	if (keycode == 11)
		sh->b = ((sh->b -= 10) < 0) ? 0 : sh->b - 10;
	if (keycode == 17)
		sh->r = ((sh->r += 10) > 255) ? 255 : sh->r + 10;
	if (keycode == 4)
		sh->g = ((sh->g += 10) > 255) ? 255 : sh->g + 10;
	if (keycode == 45)
		sh->b = ((sh->b += 10) > 255) ? 255 : sh->b + 10;
	return (ft_key_opt(keycode, sh));
}






int max( int t1, int t2 ) {
      return ( t1 > t2 ? t1 : t2 );
}









void			ft_wire2(t_show *sh, t_point *b, t_point *a)
{
	int			i;
	int			j;

	if ((b->y - a->y) == 0)
	{
		ft_putstr("выход из условия в wire");
		return ;
	}
	i = a->y;
	j = ((b->x - a->x) * (i - a->x)) / (b->y - a->y) + a->y;
	while (i < b->y)
	{
		while (j <= ((b->x - a->x) * (i + 1 - a->x) / (b->y - a->y)) + a->y)
			ft_my_pixel_put(sh, i, j++, ft_color(sh, b, a, i));
		while (j > ((b->x - a->x) * (i + 1 - a->x) / (b->y - a->y)) + a->y)
			ft_my_pixel_put(sh, i, j--, ft_color(sh, b, a, i));
		i++;
	}
}

void			ft_par_persp(t_show *sh, int i, int j)
{
	int			x;
	int			y;
	t_point		***c;

	c = sh->point;

	c[i][j]->x = (sh->zoom * (j)  / (c[i][j]->size_x +
				c[i][j]->size_y)) + sh->tight2;
	c[i][j]->y = (sh->zoom * (i) / (c[i][j]->size_x +
				c[i][j]->size_y)) + sh->tight;
	if (j > 0)
	{
		ft_wire(sh, c[i][j], c[i][j - 1]);
	//	if (i > 0)
//			ft_wire(sh, c[i][j], c[i + 1][j + 1]);
	}
	if (i > 0)
	//	if (j > 0)
	{
		//line(sh->mlx, sh->win, c[i][j]->x, c[i][j]->y, c[i - 1][j]->x, c[i - 1][j]->y);
		ft_wire2(sh,c[i][j], c[i - 1][j]);

		// ft_putstr("vertic\n");
	}
}
