
#include "../includes/fdf.h"

void				ft_color2(t_show *sh, int q)
{
	if (sh->color == 0)
		return ;
	else if (sh->color == 1)
		sh->b = q;
	else if (sh->color == 2)
		sh->r = q;
	else if (sh->color == 3)
		sh->g = q;
}

void				ft_exit_error(void)
{
	ft_putstr("Invalid map\n");
	exit(1);
}

void				ft_print_info3(t_show *p, char *str)
{
	if (p->color > 0)
	{
		str = "Color on ";
		mlx_string_put(p->mlx, p->win, 40, 190, 0x0FFFFFF, str);
		if (p->color == 1)
		{
			str = "blue";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
		if (p->color == 2)
		{
			str = "green";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
		if (p->color == 3)
		{
			str = "red";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
	}
	if (p->color == 0)
	{
		str = "No color. Press 'r', 'g', 'b'";
		mlx_string_put(p->mlx, p->win, 40, 190, 0x0FFFFFF, str);
	}
}

void				ft_print_info2(t_show *p, char *str)
{
	str = "right click :";
	mlx_string_put(p->mlx, p->win, 40, 110, 0x0FFFFFF, str);
	str = " change the colors:";
	mlx_string_put(p->mlx, p->win, 170, 110, 0x0FFFFFF, str);
	str = " g:";
	mlx_string_put(p->mlx, p->win, 385, 110, 0x0FFFFFF, str);
	str = ft_itoa(p->r);
	mlx_string_put(p->mlx, p->win, 420, 110, 0x0FFFFFF, str);
	str = " r:";
	mlx_string_put(p->mlx, p->win, 385, 130, 0x0FFFFFF, str);
	str = ft_itoa(p->g);
	mlx_string_put(p->mlx, p->win, 420, 130, 0x0FFFFFF, str);
	str = " b:";
	mlx_string_put(p->mlx, p->win, 385, 150, 0x0FFFFFF, str);
	str = ft_itoa(p->b);
	mlx_string_put(p->mlx, p->win, 420, 150, 0x0FFFFFF, str);
	str = "Opacite :";
	mlx_string_put(p->mlx, p->win, 40, 230, 0x0FFFFFF, str);
	str = ft_itoa(p->opt);
	mlx_string_put(p->mlx, p->win, 420, 230, 0x0FFFFFF, str);
	ft_print_info3(p, str);
}

void				ft_print_info(t_show *p)
{
	char			*str;

	str = "Escape      :";
	mlx_string_put(p->mlx, p->win, 40, 10, 0x0FFFFFF, str);
	str = " leave the program";
	mlx_string_put(p->mlx, p->win, 170, 10, 0x0FFFFFF, str);
	str = "+ / -      :";
	mlx_string_put(p->mlx, p->win, 40, 30, 0x0FFFFFF, str);
	str = " zoom in / out:";
	mlx_string_put(p->mlx, p->win, 170, 30, 0x0FFFFFF, str);
	str = ft_itoa(p->zoom);
	mlx_string_put(p->mlx, p->win, 420, 30, 0x0FFFFFF, str);
	str = "scroll wheel   :";
	mlx_string_put(p->mlx, p->win, 40, 70, 0x0FFFFFF, str);
	str = " modify the altitude:";
	mlx_string_put(p->mlx, p->win, 170, 70, 0x0FFFFFF, str);
	str = ft_itoa(p->deep);
	mlx_string_put(p->mlx, p->win, 420, 70, 0x0FFFFFF, str);
	str = "'0':        reinitialize the map";
	mlx_string_put(p->mlx, p->win, 40, 270, 0x0FFFFFF, str);
	ft_print_info2(p, str);
}

