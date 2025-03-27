/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:47:59 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 14:17:34 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	calc_percentage(int start, int end, int value)
{
	double	range;
	double	position;

	range = end - start;
	position = value - start;
	if (!range)
		return (1.0);
	return (position / range);
}

int	calc_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

void	change_color(t_data *fdf)
{
	fdf -> color_change = !fdf -> color_change;
}

int	color_calc(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = calc_percentage(start.x, end.x, current.x);
	else
		percentage = calc_percentage(start.y, end.y, current.y);
	r = calc_light((start.color >> RS) & BM,
			(end.color >> RS) & BM, percentage);
	g = calc_light((start.color >> GS) & BM,
			(end.color >> GS) & BM, percentage);
	b = calc_light(start.color & BM, end.color & BM, percentage);
	return ((r << RS) | (g << GS) | b);
}

int	z_color_calc(t_data *fdf, int height)
{
	double	percentage;

	percentage = calc_percentage(fdf-> map-> min_z, fdf-> map-> max_z, height);
	if (fdf -> color_change)
	{
		if (percentage < 0.7)
			return (WHITE);
		else
			return (N_BLUE);
	}
	else
	{
		if (percentage < 0.1)
			return (N_ORANGE);
		else if (percentage < 0.5)
			return (N_PINK);
		else if (percentage < 0.7)
			return (WHITE);
		else
			return (N_YELLOW);
	}
}
