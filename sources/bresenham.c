/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:26:57 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/28 13:33:33 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int absolute_val(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	init_br(t_point *start, t_point *end, t_point *delta, t_point *sign)
{
	delta -> x = absolute_val(end -> x - start -> x);
	delta -> y = absolute_val(end -> y - start -> y);
	sign -> x = -1;
	sign -> y = -1;
	if (start -> x < end -> x)
		sign -> x = 1;
	if (start -> y < end -> y)
		sign -> y = 1;
}

void	bresenham(t_data *fdf, t_point start, t_point end)
{
	t_point	c;
	t_point	sign;
	t_point	delta;
	int		line;
	int		temp;

	init_br(&start, &end, &delta, &sign);
	line = delta.x + delta.y;
	c = start;
	while (c.x != end.x || c.y != end.y)
	{
		put_pixel(fdf, c.x, c.y, color_calc(c, start, end, delta));
		temp = line * 2;
		if (temp > delta.y)
		{
			line = line + delta.y;
			c.x = c.x + sign.x;
		}
		if (temp < delta.x)
		{
			line = line + delta.x;
			c.y = c.y + sign.y;
		}
	}
}