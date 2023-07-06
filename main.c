/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:14:15 by anayef            #+#    #+#             */
/*   Updated: 2023/07/06 12:46:09 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_msg(void)
{
	ft_putstr("Invalid input.\n");
	ft_putstr("Usage: ./fractol <fractal_type> [options]\n");
	ft_putstr("Fractal Types:\n");
	ft_putstr(" - Julia Set: ./fractol julia <real> <imaginary>\n");
	ft_putstr(" (Real and imaginary values range between -2 and 2)\n");
	ft_putstr(" - Mandelbrot Set: ./fractol mandelbrot\n");
	ft_putstr(" - Tricorn Set: ./fractol tricorn\n");
	exit(1);
}

void	check_args(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0' && (ft_isdigit(s[i])
			|| s[i] == '.' || s[i] == '+' || s[i] == '-'))
	{
		if (i > 0 && (s[i] == '+' || s[i] == '-'))
			print_msg();
		if (s[i] == '.')
			count ++;
		if (count > 1)
			print_msg();
		i++;
	}
	if (s[i] != '\0')
		print_msg();
	if (ft_atoi_double(s) < -2 || ft_atoi_double(s) > 2)
		print_msg();
}

void	check_input(t_cmd *e, int argc, char *argv[])
{
	e->var.julia.real = 0;
	e->var.julia.imag = 0;
	e->var.tricorn = 0;
	e->var.mandelbrot = 2;
	if (argc < 2)
		print_msg();
	else if (ft_strncmp(ft_toupper(argv[1]), "JULIA", 5) == 0)
	{
		if (argc != 4)
			print_msg();
		check_args(argv[2]);
		check_args(argv[3]);
		e->var.julia.real = ft_atoi_double(argv[2]);
		e->var.julia.imag = ft_atoi_double(argv[3]);
	}
	else if (ft_strncmp(ft_toupper(argv[1]), "MANDELBROT", 10) == 0)
	{
		if (argc != 2)
			print_msg();
		e->var.mandelbrot = 2;
	}
	else if (ft_strncmp((ft_toupper(argv[1])), "TRICORN", 7) == 0 && argc == 2)
		e->var.tricorn = 1;
	else
		print_msg();
}

int	main(int argc, char *argv[])
{
	t_cmd	e;

	e.argc = argc;
	e.argv = argv;
	check_input(&e, argc, argv);
	e.mlx.mlx = mlx_init();
	if (e.mlx.mlx == NULL)
	{
		ft_putstr("Failed to initialize MLX.\n");
		exit(1);
	}
	set_view(&e);
	e.mlx.win = mlx_new_window(e.mlx.mlx, WIDTH, HEIGHT, "Julia Set");
	e.img.img = mlx_new_image(e.mlx.mlx, WIDTH, HEIGHT);
	e.img.addr = mlx_get_data_addr(e.img.img, &e.img.bits_per_pixel,
			&e.img.line_length, &e.img.endian);
	ft_render(&e.mlx, &e.var, &e.img);
	mlx_put_image_to_window(e.mlx.mlx, e.mlx.win, e.img.img, 0, 0);
	mlx_key_hook(e.mlx.win, ft_keypress, &e);
	mlx_mouse_hook(e.mlx.win, mouse_events, &e);
	mlx_hook(e.mlx.win, 17, 1L << 3, destroy_win, &e);
	mlx_loop(e.mlx.mlx);
	return (0);
}
