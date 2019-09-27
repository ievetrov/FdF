
#include "../includes/fdf.h"

void				ft_reset(t_show *sh)
{
	sh->deep = 0;
	sh->tight = 0;
	sh->tight2 = 0;
	sh->zoom = WIDTH;
	sh->persp = 1;
	sh->r = 255;
	sh->g = 255;
	sh->b = 255;
	sh->opt = 0;
	sh->color = 0;
}

void				ft_error(int tmp, int spaces)
{
	if (tmp != 0 && (tmp != spaces))
		ft_exit_error();
}

void				ft_get_map_hight(t_show *sh)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < sh->point[0][0]->size_y)
	{
		j = 0;
		while (j < sh->point[i][0]->size_x)
		{
			if (sh->point[i][j]->z > sh->max_hight)
				sh->max_hight = sh->point[i][j]->z;
			if (sh->point[i][j]->z < sh->min_hight)
				sh->min_hight = sh->point[i][j]->z;
			j++;
		}
		i++;
	}
}

int					main(int argc, char **argv)
{
	t_map			*map;
	t_show			*sh;

	if (argc != 2)
	{
		ft_putstr("Invalide argument\n");
		return (0);
	}
	sh = (t_show *)malloc(sizeof(t_show));
	map = (t_map *)malloc(sizeof(t_map));
	map->argv = argv;
	sh->point = ft_get_coord(map);
	ft_get_map_hight(sh);
	ft_build_mlx(sh);
	free(map);
	free(sh->point);
	free(sh);
	return (0);
}
