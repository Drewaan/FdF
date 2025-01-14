/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:29 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/12/04 05:18:08 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	map_free(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map -> z_2d)
	{
		i = -1;
		while (++i < map -> height && map -> z_2d[i])
			free(map -> z_2d[i]);
		free(map -> z_2d);
	}
	if (map -> colors)
	{
		i = -1;
		while (++i < map -> height && map -> colors[i])
			free(map -> colors[i]);
		free(map -> colors);
	}
	free (map);
}

void	map_alloc(t_map *map)
{
	int	i;

	map -> z_2d = ft_calloc(map -> height, sizeof(int *));
	map -> colors = ft_calloc(map -> height, sizeof(int *));
	if (!map -> z_2d || !map -> colors)
	{
		map_free(map);
		error_msg(MEM_ALLOC_ERROR);
	}
	i = -1;
	while (++i < map -> height)
	{
		map -> z_2d[i] = ft_calloc(map -> width, sizeof(int));
		map -> colors[i] = ft_calloc(map -> width, sizeof(int));
		if (!map -> z_2d || !map -> colors)
		{
			map_free(map);
			error_msg(MEM_ALLOC_ERROR);
		}
	}
}

int	close_window(t_data *fdf)
{
	if (!fdf)
		return (MEM_ALLOC_ERROR);
	mlx_destroy_image(fdf -> mlx, fdf -> img -> img);
	mlx_destroy_window(fdf -> mlx, fdf -> window);
	mlx_destroy_display(fdf -> mlx);
	if (fdf -> img)
		free (fdf -> img);
	map_free(fdf -> map);
	free(fdf -> mlx);
	free(fdf -> mlx);
	error_msg(SUCCESS);
	return (SUCCESS);
}

