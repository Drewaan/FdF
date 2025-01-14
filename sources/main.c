/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:05:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/12/04 05:16:03 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	init_mlx(t_data *fdf)
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

static void	call_mlx(t_map *map)
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

int	main(int argc, char **argv)
{
	char	*file;
	t_map	*map;

	if (argc != 2)
		error_msg(INVALID_ARGS_ERROR);
	file = argv[1];
	check_filename(file);
	map = init_map(file);
	call_mlx(map);
	map_free(map);
	return (SUCCESS);
}
