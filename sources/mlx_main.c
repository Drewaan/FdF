/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:21:02 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 13:56:41 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_mlx(t_data *fdf)
{
	fdf -> mlx = mlx_init();
	if (!fdf -> mlx)
	{
		map_free(fdf -> map);
		free(fdf);
		error_msg(MLX_ERROR);
	}
	fdf -> img -> img = mlx_new_image(fdf -> mlx, W_WIDTH, W_HEIGHT);
	fdf -> window = mlx_new_window(fdf -> mlx, W_WIDTH, W_HEIGHT, "Drew's FdF");
	if (!fdf -> window || !fdf -> img)
	{
		close_window(fdf);
		error_msg(MLX_ERROR);
	}
	fdf -> img -> addres = mlx_get_data_addr(fdf -> img -> img,
			&fdf -> img -> bpp, &fdf -> img -> ln_len, &fdf -> img -> endian);
}

void	call_mlx(t_map *map)
{
	t_data	*fdf;

	fdf = data_init(map);
	if (!fdf)
		error_msg(close_window(fdf));
	init_mlx(fdf);
	mlx_hook(fdf -> window, 2, (1L << 0), &handle_key, fdf);
	mlx_hook(fdf -> window, 17, 0, &close_window, fdf);
	design_map(fdf);
	mlx_loop(fdf -> mlx);
}
