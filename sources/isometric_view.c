/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:48:00 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 16:02:06 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//pi/ 6 = 0.52359877559 
void	isometric(t_data *fdf, int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	if (!fdf -> isometric)
		return ;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.52359877559);
	*y = -z + (prev_x + prev_y) * sin(0.52359877559);
}
