/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:12:38 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 14:06:57 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_greater(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	reset(t_data *fdf)
{
	fdf -> zoom = ft_greater((W_WIDTH / fdf -> map -> width / 2),
			(W_HEIGHT / fdf -> map -> height / 2));
	fdf -> shift_x = W_WIDTH / 2;
	fdf -> shift_y = (W_HEIGHT - fdf -> map -> height * fdf -> zoom) / 2;
	fdf -> isometric = 1;
	fdf -> ff = 1;
	fdf -> rot_x = 0;
	fdf -> rot_y = 0;
	fdf -> rot_z = 0;
}

t_data	*data_init(t_map *map)
{
	t_data	*fdf;

	fdf = ft_calloc(1, sizeof(t_data));
	if (!fdf)
		return (0);
	fdf -> img = ft_calloc(1, sizeof(t_img));
	if (!fdf -> img)
		return (0);
	fdf -> map = map;
	fdf -> color_change = 0;
	reset(fdf);
	return (fdf);
}
