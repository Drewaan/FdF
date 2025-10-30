/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:52:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/03/27 16:01:31 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel(t_data *fdf, int x, int y, int color)
{
	int	pixel;

	if (x >= W_WIDTH || y >= W_HEIGHT || x < 0 || y < 0)
		return ;
	pixel = (y * fdf -> img -> ln_len) + (x * (fdf -> img -> bpp / 8));
	if (fdf -> img -> endian == 1)
	{
		fdf -> img -> addres[pixel + 0] = (color >> AS);
		fdf -> img -> addres[pixel + 1] = (color >> RS) & BM;
		fdf -> img -> addres[pixel + 2] = (color >> GS) & BM;
		fdf -> img -> addres[pixel + 3] = (color) & BM;
	}
	else if (fdf -> img -> endian == 0)
	{
		fdf -> img -> addres[pixel + 0] = (color) & BM;
		fdf -> img -> addres[pixel + 1] = (color >> GS) & BM ;
		fdf -> img -> addres[pixel + 2] = (color >> RS) & BM ;
		fdf -> img -> addres[pixel + 3] = (color >> AS);
	}
}

void	design_map(t_data *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf -> img-> addres, W_WIDTH * W_HEIGHT * (fdf -> img -> bpp / 8));
	if (fdf -> zoom)
	{
		y = -1;
		while (++y < fdf -> map -> height)
		{
			x = -1;
			while (++x < fdf -> map -> width)
			{
				if (x < fdf -> map -> width - 1)
					bresenham(fdf, transformation(fdf, create_point(x, y, fdf)),
						transformation(fdf, create_point(x + 1, y, fdf)));
				if (y < fdf -> map -> height - 1)
					bresenham(fdf, transformation(fdf, create_point(x, y, fdf)),
						transformation(fdf, create_point(x, y + 1, fdf)));
			}
		}
	}
	mlx_put_image_to_window(fdf -> mlx, fdf -> window, fdf -> img -> img, 0, 0);
	draw_controls(fdf);
}

void	draw_controls(t_data *fdf)
{
	void	*mlx;
	void	*window;
	int		vp;

	mlx = fdf -> mlx;
	window = fdf -> window;
	vp = 20;
	mlx_string_put(mlx, window, 25, vp += 30, WHITE, "CONSTROLS:");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'R' : RESET");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'W' : MOVE DOWN");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'A' : MOVE RIGHT");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'D' : MOVE LEFT");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'C' : CHANGE COLOR");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'+'/'-' : ZOOM IN/OUT");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'UP'/'DOWN' : FLATTEN");
	mlx_string_put(mlx, window, 25, vp += 30, WHITE, "ROTATE VIEW:");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'1'/'2' : X-AXIS");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'3'/'4' : Y-AXIS");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'5'/'6' : Z-AXIS");
	mlx_string_put(mlx, window, 25, vp += 30, WHITE, "TOGGLE PERSPECTIVE:");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN,
		"'TAB' : ISOMETRIC/PARALLEL");
	mlx_string_put(mlx, window, 25, vp += 30, WHITE, "EXIT:");
	mlx_string_put(mlx, window, 40, vp += 20, CYAN, "'ESC' : CLOSE WINDOW");
}
