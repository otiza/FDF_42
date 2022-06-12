/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaiza <amaaiza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:46:22 by amaaiza           #+#    #+#             */
/*   Updated: 2021/09/19 15:47:07 by amaaiza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <math.h>

typedef struct s_point
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_point;

typedef struct s_cord
{
	int			x;
	int			y;
	int			z;
}				t_cord;

typedef struct s_draw_var
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_draw_var;

typedef struct s_map
{
	double		angle;
	int			error;
	int			color;
	int			zoom;
	int			height;
	int			xplus;
	int			yplus;
	int			projection;
	int			xp;
	int			yp;
	int			**tab;
	void		*mlx_ptr;
	void		*win_ptr;
	int			margex;
	t_cord		**cords;
}				t_map;

void			ft_free(char **tab);
int				**allocate(int i, int j, t_map *map);
int				**read_map(int fd, t_map *map);
void			draw(t_point p, t_map *map);
void			isoproject(int *x, int *y, int z, t_map *map);
int				**fill_tab( int fd, int **tab);
void			fulldraw(t_map *map, int x, int y);
int				key_press(int keycode, t_map *param);
void			fill_cords(t_map *map);
void			menu(t_map *map);
void			fulldraw(t_map *map, int x, int y);
int				key_press(int keycode, t_map *map);
void			free_exit(t_map *map, int j);
void			ft_terminate(char *s);
int				get_next_line(int fd, char **line);
int				ft_wdcounter(char const *str, char c);
char			**ft_strsplit(char const *s, char c);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
int				ft_max(int a, int b);
int				ft_abs(int a);
void			ft_strdel(char **as);

#endif
