/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:26:50 by anayef            #+#    #+#             */
/*   Updated: 2023/07/05 12:13:34 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_win(t_cmd *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

void	move_map_arrows(int keycode, t_cmd *e)
{
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	if (keycode == 125)
	{
		e->mlx.virt_min.imag += MOVEFACTOR;
		e->mlx.virt_max.imag += MOVEFACTOR;
	}
	else if (keycode == 124)
	{
		e->mlx.virt_min.real -= MOVEFACTOR;
		e->mlx.virt_max.real -= MOVEFACTOR;
	}
	else if (keycode == 123)
	{
		e->mlx.virt_min.real += MOVEFACTOR;
		e->mlx.virt_max.real += MOVEFACTOR;
	}
	else if (keycode == 126)
	{
		e->mlx.virt_min.imag -= MOVEFACTOR;
		e->mlx.virt_max.imag -= MOVEFACTOR;
	}
	ft_render(&e->mlx, &e->var, &e->img);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->img.img, 0, 0);
}

void	update_zoom(t_vars *mlx, double zoom_factor)
{
	mlx->virt_min.real *= zoom_factor;
	mlx->virt_max.real *= zoom_factor;
	mlx->virt_min.imag *= zoom_factor;
	mlx->virt_max.imag *= zoom_factor;
}

int	ft_keypress(int keycode, t_cmd *e)
{
	double	zoom_factor_out;
	double	zoom_factor_in;

	zoom_factor_out = 1.1;
	zoom_factor_in = 0.9;
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	else if (keycode >= 123 && keycode <= 126)
	{
		move_map_arrows(keycode, e);
	}
	else if (keycode == 69)
	{
		update_zoom(&(e->mlx), zoom_factor_in);
		move_map_arrows(keycode, e);
	}
	else if (keycode == 78)
	{
		update_zoom(&(e->mlx), zoom_factor_out);
		move_map_arrows(keycode, e);
	}
	return (0);
}

int	mouse_events(int button, int x, int y, t_cmd *e)
{
	double	zoom_factor;
	double	rel_x;
	double	rel_y;

	zoom_factor = 0.1;
	rel_x = ((double)x / WIDTH) * (e->mlx.virt_max.real - e->mlx.virt_min.real)
		+ e->mlx.virt_min.real;
	rel_y = ((double)y / HEIGHT) * (e->mlx.virt_max.imag - e->mlx.virt_min.imag)
		+ e->mlx.virt_min.imag;
	if (button == 4)
	{
		e->mlx.virt_min.real += (rel_x - e->mlx.virt_min.real) * zoom_factor;
		e->mlx.virt_max.real -= (e->mlx.virt_max.real - rel_x) * zoom_factor;
		e->mlx.virt_min.imag += (e->mlx.virt_max.imag - rel_y) * zoom_factor;
		e->mlx.virt_max.imag -= (rel_y - e->mlx.virt_min.imag) * zoom_factor;
	}
	else if (button == 5)
	{
		e->mlx.virt_min.real -= (rel_x - e->mlx.virt_min.real) * zoom_factor;
		e->mlx.virt_max.real += (e->mlx.virt_max.real - rel_x) * zoom_factor;
		e->mlx.virt_min.imag -= (rel_y - e->mlx.virt_min.imag) * zoom_factor;
		e->mlx.virt_max.imag += (e->mlx.virt_max.imag - rel_y) * zoom_factor;
	}
	move_map_arrows(button, e);
	return (0);
}
