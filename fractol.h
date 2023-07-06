/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 10:44:22 by anayef            #+#    #+#             */
/*   Updated: 2023/07/06 11:58:53 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

# ifndef CONSTUNTS

#  define CONSTUNTS
#  define MAX_ITERATION 255
#  define WIDTH 1000
#  define HEIGHT 1000
#  define MOVEFACTOR 0.05

# endif

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_complex	virt_max;
	t_complex	virt_min;
	double		zoom;
}	t_vars;

typedef struct s_fracol
{
	t_complex	julia;
	int			mandelbrot;
	int			tricorn;
}	t_fractol;

typedef struct s_cmd
{
	t_data		img;
	t_vars		mlx;
	t_fractol	var;
	int			argc;
	char		**argv;
}	t_cmd;

int			ft_keypress(int keycode, t_cmd *e);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			calculate_color(int iteration);
int			destroy_win(t_cmd *e);
int			ft_julia(t_vars *mlx, t_fractol *var, int x, int y);
int			mouse_events(int button, int x, int y, t_cmd *e);
void		ft_render(t_vars *mlx, t_fractol *var, t_data *img_data);
int			calculate_color(int iteration);
t_complex	ft_map(t_vars *mlx, int x, int y);
void		set_view(t_cmd *e);
double		ft_atoi_double(const char *nptr);
void		print_msg(void);

#endif
