/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:02:02 by anayef            #+#    #+#             */
/*   Updated: 2023/07/05 17:25:24 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_julia(t_vars *mlx, t_fractol *var, int x, int y)
{
	int			iteration;
	t_complex	z;
	t_complex	c;
	double		ztemp;

	c = var->julia;
	iteration = 0;
	z = ft_map(mlx, x, y);
	while (z.real * z.real + z.imag * z.imag < 4 && iteration < MAX_ITERATION)
	{
		ztemp = z.real * z.real - z.imag * z.imag;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = ztemp + c.real;
		iteration++;
	}
	return (iteration);
}

int	ft_mandelbrot(t_vars *mlx, int x, int y)
{
	int			iteration;
	t_complex	z;
	t_complex	c;
	t_complex	temp;

	iteration = 0;
	z.real = 0;
	z.imag = 0;
	c = ft_map(mlx, x, y);
	while (z.real * z.real + z.imag * z.imag < 4 && iteration < MAX_ITERATION)
	{
		temp.real = z.real * z.real - z.imag * z.imag + c.real;
		temp.imag = 2 * z.real * z.imag + c.imag;
		z = temp;
		iteration++;
	}
	return (iteration);
}

int	ft_tricorn(t_vars *mlx, int x, int y)
{
	int			iteration;
	t_complex	z;
	t_complex	c;
	t_complex	temp;

	iteration = 0;
	z.real = 0;
	z.imag = 0;
	c = ft_map(mlx, x, y);
	while (z.real * z.real + z.imag * z.imag < 4 && iteration < MAX_ITERATION)
	{
		temp.real = z.real * z.real - z.imag * z.imag + c.real;
		temp.imag = -2 * z.real * z.imag + c.imag;
		z = temp;
		iteration++;
	}
	return (iteration);
}

void	ft_render(t_vars *mlx, t_fractol *var, t_data *img_data)
{
	int	color;
	int	y;
	int	x;
	int	iteration;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (var->julia.real == 0 && var->julia.imag == 0
				&& var->tricorn == 0)
				iteration = ft_mandelbrot(mlx, x, y);
			else if (var->mandelbrot == 2 && var->tricorn == 0)
				iteration = ft_julia(mlx, var, x, y);
			else
				iteration = ft_tricorn(mlx, x, y);
			color = calculate_color(iteration);
			my_mlx_pixel_put(img_data, x, y, color);
			x++;
		}
		y++;
	}
}
