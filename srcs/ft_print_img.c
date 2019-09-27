
#include "../includes/fdf.h"

void			ft_my_pixel_put(t_show *sh, int i, int j, float q)
{
	int			k;

	ft_color2(sh, q);
	if ((i > 0 && j > 0 && i < WIDTH && j < HEIGHT))
	{
		sh->ret[((i * 4 + (j * sh->size_line)))] = sh->b;
		sh->ret[((i * 4 + (j * sh->size_line))) + 1] = sh->r;
		sh->ret[((i * 4 + (j * sh->size_line))) + 2] = sh->g;
		sh->ret[((i * 4 + (j * sh->size_line))) + 3] = sh->opt;
	}
}

float			ft_color(t_show *sh, t_point *b, t_point *a, int i)
{
	float		ret;
	float		dif;
	float		alt;

	dif = (float)(i - a->x) / (float)(b->x - a->x);
	alt = (float)(a->z + ((b->z - a->z) * dif)) /
	(float)(sh->max_hight - sh->min_hight);
	ret = 255 * alt;
	return (ret);
}

void			ft_wire(t_show *sh, t_point *b, t_point *a)
{
	int			i;
	int			j;

	if ((b->x - a->x) == 0)
		return ;
	i = a->x;
	j = ((b->y - a->y) * (i - a->x)) / (b->x - a->x) + a->y;
	while (i < b->x)
	{
		while (j <= ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			ft_my_pixel_put(sh, i, j++, ft_color(sh, b, a, i));
		while (j > ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			ft_my_pixel_put(sh, i, j--, ft_color(sh, b, a, i));
		i++;
	}
}

void			ft_iso_persp(t_show *sh, int i, int j)
{
	int			x;
	int			y;
	t_point		***c;

	c = sh->point;
	
	c[i][j]->x = (sh->zoom * (i + j)  / (c[i][j]->size_x +
				c[i][j]->size_y)) + sh->tight2;
	c[i][j]->y = ((sh->zoom * (c[i][j]->size_x + i - j) /
				(c[i][j]->size_x + c[i][j]->size_y) - (c[i][j]->z)
				* sh->deep) + sh->tight);		
	c[i][j]->y = c[i][j]->y / 2;
	if (j > 0)
		ft_wire(sh, c[i][j], c[i][j - 1]);
	if (i > 0)
		ft_wire(sh, c[i][j], c[i - 1][j]);
}

void			ft_choose_persp(t_show *sh, int i, int j)
{
	if (sh->persp == 1)
		ft_iso_persp(sh, i, j);
	if (sh->persp == 2)
		ft_par_persp(sh, i, j);
}
