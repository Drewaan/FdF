/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_points_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:56:11 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/28 03:33:52 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	transformation(t_data *fdf, t_point point)
{
	point.x = point.x * fdf -> zoom;
	point.y = point.y * fdf -> zoom;
	point.z = point.z * (fdf -> zoom / SF) * fdf -> ff;
	rot_x(fdf, &point.y, &point.z);
	rot_y(fdf, &point.x, &point.z);
	rot_x(fdf, &point.x, &point.y);
	isometric(fdf, &point.x, &point.y, point.z);
	point.x = point.x + fdf -> shift_x;
	point.y = point.y + fdf -> shift_y;
	return (point);
}

t_point	create_point(int x, int y, t_data *fdf)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = fdf -> map -> z_2d[y][x];
	if (fdf -> map -> iscolor)
		point.color = fdf -> map -> colors[y][x];
	else
		point.color = z_color_calculator(fdf, point.z);
	return (point);
}
