/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaiza <amaaiza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:36:39 by amaaiza           #+#    #+#             */
/*   Updated: 2021/09/18 18:06:07 by amaaiza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_line(char **split, int **tab, int i)
{
	int		j;

	j = 0;
	while (split[j] != NULL)
	{
		tab[i][j] = ft_atoi(split[j]);
		j++;
	}
}

int	**fill_tab( int fd, int **tab)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = 0;
	j = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		fill_line(split, tab, i);
		j = 0;
		while (split[j] != NULL)
		{
			ft_strdel(&split[j]);
			j++;
		}
		i++;
		free(line);
		free(split);
	}
	free(line);
	return (tab);
}

void	draw(t_point p, t_map *map)
{
	t_draw_var	v;

	v.dx = abs(p.x1 - p.x0);
	v.dy = abs(p.y1 - p.y0);
	v.sx = ((p.x0 < p.x1) * 1) + (!(p.x0 < p.x1) * -1);
	v.sy = ((p.y0 < p.y1) * 1) + (!(p.y0 < p.y1) * -1);
	v.err = ((v.dx > v.dy) * v.dx + (!(v.dx > v.dy) * -v.dy)) / 2;
	while (p.x0 != p.x1 || p.y0 != p.y1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, p.x0, p.y0, map->color);
		v.e2 = v.err;
		if (v.e2 > -v.dx)
		{
			v.err -= v.dy;
			p.x0 += v.sx;
		}
		if (v.e2 < v.dy)
		{
			v.err += v.dx;
			p.y0 += v.sy;
		}
	}
	map->color = 0xFFFFFF;
}

void	isoproject(int *x, int *y, int z, t_map *map)
{
	int	prex;
	int	prey;

	z += 0;
	prex = *x;
	prey = *y;
	*x = (prex - prey) * cos(map->angle) + 100;
	*y = -z + (prex + prey) * sin(map->angle) - 200;
}
