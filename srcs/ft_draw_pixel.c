
#include "../includes/fdf.h"

int					ft_key_opt(int keycode, t_show *sh)
{
	if (keycode == 47 && (sh->opt + 10) <= 255)
		sh->opt += 10;
	if (keycode == 43 && (sh->opt - 10) >= 0)
		sh->opt -= 10;
	if (keycode == 34)
	{
		ft_reset(sh);
		sh->persp = 1;
	}
	if (keycode == 35)
	{
		ft_reset(sh);
		sh->persp = 2;
	}
	ft_loop_key_hook(sh);
	return (0);
}

static int			ft_loop_key_hook(t_show *sh)
{
	sh->ret = mlx_get_data_addr(sh->img, &(sh->bits_per_pixel),
		&(sh->size_line), &(sh->endian));
	ft_put_point(sh);
	mlx_put_image_to_window(sh->mlx, sh->win, sh->img, 0, 0);
	mlx_destroy_image(sh->mlx, sh->img);
	sh->img = mlx_new_image(sh->mlx, WIDTH, HEIGHT);
	ft_print_info(sh);
	return (0);
}

int					ft_mouse_hook(int button, int x, int y, t_show *sh)
{
	if (button == 4)
		sh->deep += 1;
	if (button == 5)
		sh->deep -= 1;
	if (button == 1)
	{
		if ((sh->r + 10) <= 255)
			sh->r += 10;
		if ((sh->g + 10) <= 255)
			sh->g += 10;
		if ((sh->b + 10) <= 255)
			sh->b += 10;
	}
	if (button == 2)
	{
		if ((sh->r - 10) >= 0)
			sh->r -= 10;
		if ((sh->g - 10) >= 0)
			sh->g -= 10;
		if ((sh->b - 10) >= 0)
			sh->b -= 10;
	}
	ft_loop_key_hook(sh);
	return (0);
}

void				ft_put_point(t_show *sh)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < sh->point[0][0]->size_y)
	{
		j = 0;
		while (j < sh->point[i][0]->size_x)
			ft_choose_persp(sh, i, j++);
		i++;
	}
}
