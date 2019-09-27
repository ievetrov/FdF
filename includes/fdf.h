/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:39:19 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/27 02:47:32 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "math.h"
# include "../libft/libft.h"
# define WIDTH 2560
# define HEIGHT 1440
# define ESCAPE	53
# define UP		126
# define DOWN	125
# define RIGHT	124
# define LEFT	123
# define ZOOM	24
# define DEZOOM	27

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_point;

typedef struct		s_show
{
	int				s_line;
	void			*win;
	void			*mlx;
	void			*img;
	t_point			***point;
	int				deep;
	unsigned int	tight;
	unsigned int	tight2;
	int				zoom;
	int				persp;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*ret;
	int				r;
	int				g;
	int				b;
	int				min_hight;
	int				max_hight;
	int				color;
	int				opt;

}					t_show;

typedef struct		s_map
{
	char			**argv;
	char			**map;
	char			**tmp;
	int				x;
	int				y;
}					t_map;

int					ft_key_main(int keycode, t_show *sh);
int					ft_key_zoomcolor(int keycode, t_show *sh);
int					ft_key_rgb(int keycode, t_show *sh);
int					ft_key_opt(int keycode, t_show *sh);
void				ft_color2(t_show *sh, int q);
float				ft_color(t_show *sh, t_point *b, t_point *a, int i);
void				ft_exit_error(void);
void				ft_print_info(t_show *p);
void				ft_print_info2(t_show *p, char *str);
void				ft_reset(t_show *sh);
void				ft_error(int tmp, int spaces);
void				ft_exit_error();
static int			ft_loop_key_hook(t_show *sh);
void				ft_reset(t_show *sh);
void				ft_get_map(struct s_map *map);
t_point				***ft_get_coord(struct s_map *map);
int					ft_build_mlx(struct s_show *p);
int					ft_expose_hook(t_show *p);
void				ft_wire(t_show *sh, t_point *b, t_point *a);
void				ft_choose_persp(t_show *sh, int i, int j);
void				ft_iso_persp(t_show *sh, int i, int j);
void				ft_par_persp(t_show *sh, int i, int j);
void				ft_print_info(t_show *p);
int					ft_key_hook(int keycode, t_show *sh);
int					ft_mouse_hook(int button, int x, int y, t_show *sh);
int					ft_mlx_event(struct s_show *sh);
void				ft_put_point(struct s_show *sh);

#endif
