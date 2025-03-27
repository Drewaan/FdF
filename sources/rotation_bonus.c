/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:18:28 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/03/18 16:28:57 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rot_x(t_data *fdf, int *y, int *z)
{
	float	prev_y;

	prev_y = *y;
	*y = (prev_y * cos(fdf -> rot_x)) + (*z * sin(fdf -> rot_x));
	*z = (-prev_y * sin(fdf -> rot_x)) + (*z * cos(fdf -> rot_x));
}

void	rot_y(t_data *fdf, int *x, int *z)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(fdf -> rot_y)) + (*z * sin(fdf -> rot_y));
	*z = (-prev_x * sin(fdf -> rot_y)) + (*z * cos(fdf -> rot_y));
}

void	rot_z(t_data *fdf, int *x, int *y)
{
	float	prev_x;

	prev_x = *x;
	*x = (*x * cos(fdf -> rot_z)) - (*y * sin(fdf -> rot_z));
	*y = (prev_x * sin(fdf -> rot_z)) + (*y * cos(fdf -> rot_z));
}
