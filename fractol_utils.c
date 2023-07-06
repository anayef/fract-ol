/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:21:38 by anayef            #+#    #+#             */
/*   Updated: 2023/07/06 13:21:58 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_color(int iteration)
{
	unsigned int	color;
	int				offset;

	offset = 0;
	color = ((255 - iteration * 4 + offset) % 255) << 24
		| ((iteration + offset) % 255) << 16
		| ((iteration * 2 + offset) % 255) << 8
		| ((iteration * 3 + offset) % 255);
	return (color);
}

t_complex	ft_map(t_vars *mlx, int x, int y)
{
	t_complex	z;

	z.real = mlx->virt_min.real
		+ (x * ((mlx->virt_max.real - mlx->virt_min.real) / (WIDTH -1)));
	z.imag = mlx->virt_max.imag
		- (y * ((mlx->virt_max.imag - mlx->virt_min.imag) / (HEIGHT -1)));
	return (z);
}

void	set_view(t_cmd *e)
{
	e->mlx.virt_max.real = 2.0;
	e->mlx.virt_max.imag = 2.0;
	e->mlx.virt_min.real = -2.0;
	e->mlx.virt_min.imag = -2.0;
	e->mlx.zoom = 1.0;
}

double	ft_atoi_double(const char *str)
{
	int		i;
	int		sign;
	double	res;
	double	division;

	i = 0;
	sign = 1;
	res = 0.0;
	division = 1.0;
	while (str[i] != '.' && str[i] != '\0')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	res = sign * ft_atoi(str);
	if (str[i] == '.')
	{
		i++;
		while (str[i] != '\0')
		{
			res = res + (str[i++] - '0') / (10 * division);
			division *= 10.0;
		}
	}
	return (sign * res);
}
