/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:24 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 13:57:01 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	convert_hex_color(char *color, t_map *map)
{
	while (ft_isdigit(*color) || *color == '-'
		|| *color == '+' || *color == ',')
		color++;
	if (*color && *color == 'x')
	{
		map -> iscolor = 1;
		color++;
		return (ft_atoi_base(color, BASE_HEXA));
	}
	return (WHITE);
}

int	find_width(char **split)
{
	int	i;

	if (!split)
		error_msg(MAP_EMPTY_ERROR);
	if (!*split)
		error_msg(MAP_EMPTY_ERROR);
	i = 0;
	while (split[i])
		i++;
	ft_free(split);
	return (i);
}

int	z_value(int z, t_map *map)
{
	if (z < map -> min_z)
		map -> min_z = z;
	if (z > map -> max_z)
		map -> max_z = z;
	return (z);
}
